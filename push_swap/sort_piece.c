/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 02:03:37 by yejin             #+#    #+#             */
/*   Updated: 2022/04/10 02:04:53 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_to_bottom_a(t_HEAD *a, t_HEAD *b, t_CHEAD *cmd)
{
	if (a->back->prev->prev->data < a->back->prev->data && \
		a->back->data < a->back->prev->data)
	{
		if (a->count != 3)
		{
			ra(a, b, cmd, 0);
			sa(a, b, cmd, 0);
		}
		rra(a, b, cmd, 0);
	}
	else if (a->back->prev->prev->data < a->back->data && \
			a->back->prev->data < a->back->data)
	{
		if (a->count == 3)
			ra(a, b, cmd, 0);
		else
		{
			sa(a, b, cmd, 0);
			ra(a, b, cmd, 0);
			sa(a, b, cmd, 0);
			rra(a, b, cmd, 0);
		}
	}
}

void	big_to_bottom_b(t_HEAD *a, t_HEAD *b, t_CHEAD *cmd)
{
	if (b->back->prev->data < b->back->prev->prev->data && \
			b->back->prev->data < b->back->data)
	{
		if (b->count != 3)
		{
			rb(a, b, cmd, 0);
			sb(a, b, cmd, 0);
		}
		rrb(a, b, cmd, 0);
	}
	else if (b->back->data < b->back->prev->prev->data && \
			b->back->data < b->back->prev->data)
	{
		if (b->count == 3)
			rb(a, b, cmd, 0);
		else
		{
			sb(a, b, cmd, 0);
			rb(a, b, cmd, 0);
			sb(a, b, cmd, 0);
			rrb(a, b, cmd, 0);
		}
	}
}

void	sort_piece_a(int n, t_HEAD *a, t_HEAD *b, t_CHEAD *cmd)
{
	if (n == 1)
		return ;
	if (n == 2 && a->back->prev->data < a->back->data)
		sa(a, b, cmd, 0);
	else if (n == 3)
	{
		big_to_bottom_a(a, b, cmd);
		if (a->back->prev->data < a->back->data)
			sa(a, b, cmd, 0);
	}
}

void	sort_piece_b(int n, t_HEAD *a, t_HEAD *b, t_CHEAD *cmd)
{
	if (n == 1)
		return ;
	if (n == 2 && b->back->prev->data > b->back->data)
		sb(a, b, cmd, 0);
	else if (n == 3)
	{
		big_to_bottom_b(a, b, cmd);
		if (b->back->prev->data > b->back->data)
			sb(a, b, cmd, 0);
	}
}
