/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 11:49:16 by yejin             #+#    #+#             */
/*   Updated: 2022/05/15 22:46:07 by yejin            ###   ########.fr       */
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

void	free_mem(t_lst **lst, char **pnew)
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
