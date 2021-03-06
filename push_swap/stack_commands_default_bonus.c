/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_commands_default_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 02:03:43 by yejin             #+#    #+#             */
/*   Updated: 2022/04/10 02:04:55 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	sa(t_HEAD *a)
{
	int	temp;

	temp = a->back->data;
	a->back->data = a->back->prev->data;
	a->back->prev->data = temp;
}

void	sb(t_HEAD *b)
{
	int	temp;

	temp = b->back->data;
	b->back->data = b->back->prev->data;
	b->back->prev->data = temp;
}

void	pa(t_HEAD *a, t_HEAD *b)
{
	int	temp;

	temp = b->back->data;
	pop_back(b);
	push_back(a, temp, b);
}

void	pb(t_HEAD *a, t_HEAD *b)
{
	int	temp;

	temp = a->back->data;
	pop_back(a);
	push_back(b, temp, a);
}
