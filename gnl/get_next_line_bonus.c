/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 11:48:53 by yejin             #+#    #+#             */
/*   Updated: 2021/11/23 16:24:31 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

	pnew_l = 0;
	while (pnew && *(pnew + pnew_l))
		pnew_l++;
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
		if (nl != lst->last || (lst->buffer)[nl - 1] == '\n')
			break ;
		lst->last = read(fd, lst->buffer, BUFFER_SIZE);
		lst->curr = 0;
		if (lst->last == 0)
			break ;
	}
	return (pnew);
}

t_list	*ft_lstgetone(t_list **lst, int fd)
{
	char	*pnew;
	t_list	*curr;

	pnew = NULL;
	if (*lst == NULL || (*lst)->fd == fd)
	{
		if (!ft_lstadd(lst, fd))
		{
			free_mem(lst, &pnew, fd);
			return (NULL);
		}
		return (*lst);
	}
	curr = ft_lstfind(lst, fd);
	if (!ft_lstadd(&(curr->next), fd))
	{
		free_mem(lst, &pnew, fd);
		return (NULL);
	}
	return (curr->next);
}

char	*get_next_line(int fd)
{
	static t_list	*lst;
	t_list			*curr;
	char			*pnew;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	pnew = NULL;
	curr = ft_lstgetone(&lst, fd);
	if (curr == NULL)
	{
		free_mem(&lst, &pnew, fd);
		return (NULL);
	}
	pnew = get_line(fd, curr);
	if (pnew == NULL || *pnew == '\0')
	{
		free_mem(&lst, &pnew, fd);
		return (NULL);
	}
	return (pnew);
}
