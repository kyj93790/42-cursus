/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 11:49:16 by yejin             #+#    #+#             */
/*   Updated: 2021/11/23 14:26:29 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_strcpy(char *dst, char *src)
{
	int	i;

	if (src == NULL)
	{
		*dst = '\0';
		return ;
	}
	i = 0;
	while (*(src + i))
	{
		*(dst + i) = *(src + i);
		i++;
	}
	*(dst + i) = '\0';
}

void	free_element(t_list *temp)
{
	if (temp)
	{
		if (temp->buffer)
		{
			free(temp->buffer);
			temp->buffer = NULL;
		}
		free(temp);
		temp = NULL;
	}
}

void	free_mem(t_list **lst, char **pnew, int fd)
{
	t_list	*temp;
	t_list	*curr;

	if (*lst)
	{
		if ((*lst)->fd == fd)
		{
			temp = *lst;
			*lst = temp->next;
		}
		else
		{
			curr = ft_lstfind(lst, fd);
			temp = curr->next;
			curr->next = temp->next;
		}
		free_element(temp);
	}
	if (*pnew)
	{
		free(*pnew);
		*pnew = NULL;
	}
}