/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 11:49:16 by yejin             #+#    #+#             */
/*   Updated: 2021/11/23 16:17:57 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (*(s + i))
		i++;
	return (i);
}

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

void	free_mem(t_list **lst, char **pnew)
{
	if (*lst)
	{
		if ((*lst)->buffer)
		{
			free((*lst)->buffer);
			(*lst)->buffer = NULL;
		}
		free(*lst);
		*lst = NULL;
	}
	if (*pnew)
	{
		free(*pnew);
		*pnew = NULL;
	}
}
