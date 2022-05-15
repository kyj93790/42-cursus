/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 11:48:53 by yejin             #+#    #+#             */
/*   Updated: 2022/05/15 23:40:46 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_lstadd(t_lst **lst, int fd)
{
	if (*lst != NULL)
	{
		if ((*lst)->curr >= (*lst)->last)
		{
			(*lst)->last = read(fd, (*lst)->buffer, BUFFER_SIZE);
			if ((*lst)->last <= 0)
				return (0);
			(*lst)->curr = 0;
		}
		return (1);
	}
	*lst = (t_lst *)malloc(sizeof(t_lst));
	if (*lst == NULL)
		return (0);
	(*lst)->buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if ((*lst)->buffer == NULL)
		return (0);
	(*lst)->last = read(fd, (*lst)->buffer, BUFFER_SIZE);
	if ((*lst)->last <= 0)
		return (0);
	(*lst)->curr = 0;
	(*lst)->next = NULL;
	return (1);
}

int	check_line(t_lst *lst)
{
	int	i;

	i = lst->curr;
	while (i < lst->last)
	{
		if ((lst->buffer)[i] == '\n')
			return (++i);
		i++;
	}
	return (i);
}

char	*add_line(t_lst *lst, char *pnew, int nl)
{
	char	*result;
	int		pnew_l;
	int		i;

	pnew_l = ft_strlen(pnew);
	result = (char *)malloc(sizeof(char) * (nl - lst->curr + pnew_l + 1));
	if (result == 0)
		return (0);
	ft_strcpy(result, pnew);
	if (pnew)
		free(pnew);
	i = 0;
	while (lst->curr < nl)
	{
		result[pnew_l + i] = (lst->buffer)[lst->curr];
		(lst->curr)++;
		i++;
	}
	result[pnew_l + i] = '\0';
	return (result);
}

char	*get_line(int fd, t_lst *lst)
{
	char	*pnew;
	int		nl;

	pnew = NULL;
	while (1)
	{
		nl = check_line(lst);
		pnew = add_line(lst, pnew, nl);
		if (pnew == NULL)
			return (NULL);
		if (nl != lst->last || (lst->buffer)[nl - 1] == '\n')
			break ;
		lst->last = read(fd, lst->buffer, BUFFER_SIZE);
		lst->curr = 0;
		if (lst->last == 0)
			break ;
	}
	return (pnew);
}

char	*get_next_line(int fd)
{
	static t_lst	*lst;
	char			*pnew;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	pnew = NULL;
	if (!ft_lstadd(&lst, fd))
	{
		free_mem(&lst, &pnew);
		return (NULL);
	}
	pnew = get_line(fd, lst);
	if (pnew == NULL || *pnew == '\0')
	{
		free_mem(&lst, &pnew);
		return (NULL);
	}
	return (pnew);
}
