/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 11:49:16 by yejin             #+#    #+#             */
/*   Updated: 2021/11/23 18:53:03 by yejikim          ###   ########.fr       */
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
	(*lst)->next = NULL;
	(*lst)->fd = fd;
	(*lst)->buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if ((*lst)->buffer == NULL)
		return (0);
	(*lst)->last = read(fd, (*lst)->buffer, BUFFER_SIZE);
	if ((*lst)->last <= 0)
		return (0);
	(*lst)->curr = 0;
	return (1);
}

t_list	*ft_lstfind(t_list **lst, int fd)
{
	t_list	*curr;

	curr = *lst;
	while (curr)
	{
		if (curr->next == NULL)
			return (curr);
		else if (curr->next->fd == fd)
			return (curr);
		curr = curr->next;
	}
	return (curr);
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
			if (curr->next == NULL)
				return ;
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
