/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 18:30:09 by yejin             #+#    #+#             */
/*   Updated: 2021/11/18 18:30:10 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*curr;
	t_list	*pcur;

	curr = *lst;
	while (curr)
	{
		pcur = curr;
		curr = curr->next;
		ft_lstdelone(pcur, del);
	}
	*lst = NULL;
}
