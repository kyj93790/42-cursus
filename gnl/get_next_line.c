/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 11:48:53 by yejin             #+#    #+#             */
/*   Updated: 2021/11/23 16:23:22 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_lstadd(t_list **lst, int fd)
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
	*lst = (t_list *)malloc(sizeof(t_list));
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

int	check_line(t_list *lst)
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

char	*add_line(t_list *lst, char *pnew, int nl)
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

char	*get_line(int fd, t_list *lst)
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
		// 버퍼 끝까지 가기 전에 엔터를 만나거나 || 버퍼 끝까지 가긴 했지만 버퍼 끝에 개행이 있었던 경우
		if (nl != lst->last || (lst->buffer)[nl - 1] == '\n')	// enter를 만난 것.
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
	static t_list	*lst;
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
