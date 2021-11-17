/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejikim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 01:17:21 by yejin             #+#    #+#             */
/*   Updated: 2021/11/17 17:09:28 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*pnew;

	pnew = (t_list *)malloc(sizeof(t_list));
	if (pnew == 0)
		return (0);
	pnew->content = content;
	pnew->next = NULL;
	return (pnew);
}
