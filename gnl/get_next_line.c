/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 11:48:53 by yejin             #+#    #+#             */
/*   Updated: 2021/11/22 00:20:39 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_lstadd(t_list **lst)
{
	if (*lst != NULL)
		return (1);
	*lst = (t_list *)malloc(sizeof(t_list));
	if (*lst == NULL)
		return (0);
	(*lst)->buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if ((*lst)->buffer == NULL)
		return (0);
	(*lst)->curr = 0;
	(*lst)->last = 0;
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
	if (i != 0 && i < BUFFER_SIZE)
		return (i);
	return (-1);
}

char	*add_line(t_list *lst, char *pnew, int line_i)
{
	char	*result;
	int		pnew_l;
	int		i;

	if (line_i < 0)
		line_i = lst->last;
	pnew_l = ft_strlen(pnew);
	result = (char *)malloc(sizeof(char) * (line_i - lst->curr + pnew_l + 1));
	if (result == 0)
		return (0);
	ft_strcpy(result, pnew);
	free(pnew);
	i = 0;
	while (lst->curr < line_i)
	{
		result[pnew_l + i] = (lst->buffer)[lst->curr];
		(lst->curr)++;
		i++;
	}
	result[pnew_l + i] = '\0';
	return (result);
}

char	*get_next_line(int fd)
{
	static t_list	*lst;
	char			*pnew;
	int				line_i;

	if (fd < 0)
		return (NULL);
	pnew = NULL;
	if (!ft_lstadd(&lst))
		return (NULL);
	while (1)
	{
		line_i = check_line(lst);
		pnew = add_line(lst, pnew, line_i);
		if (pnew == NULL)
			return (NULL);
		if (line_i >= 0)
			break ;
		lst->last = read(fd, lst->buffer, BUFFER_SIZE);
		lst->curr = 0;
		if (lst->last == 0)
		{
			free_mem(lst);
			break ;
		}
	}
	return (pnew);
}
