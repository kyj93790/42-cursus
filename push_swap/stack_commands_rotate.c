/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_commands_rotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 02:03:50 by yejin             #+#    #+#             */
/*   Updated: 2022/04/10 02:04:57 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_HEAD *a, t_HEAD *b, t_CHEAD *cmd, t_cnt *cnt)
{
	if (cnt)
		(cnt->ra)++;
	if (a->count <= 1)
		return ;
	a->front = a->back;
	a->back = a->back->prev;
	cmd_push("ra", a, b, cmd);
}

void	rb(t_HEAD *a, t_HEAD *b, t_CHEAD *cmd, t_cnt *cnt)
{
	if (cnt)
		(cnt->rb)++;
	if (b->count <= 1)
		return ;
	b->front = b->back;
	b->back = b->back->prev;
	cmd_push("rb", a, b, cmd);
}

void	rra(t_HEAD *a, t_HEAD *b, t_CHEAD *cmd, t_cnt *cnt)
{
	if (cnt)
		(cnt->rra)++;
	if (a->count <= 1)
		return ;
	a->back = a->front;
	a->front = a->front->next;
	cmd_push("rra", a, b, cmd);
}

void	rrb(t_HEAD *a, t_HEAD *b, t_CHEAD *cmd, t_cnt *cnt)
{
	if (cnt)
		(cnt->rrb)++;
	if (b->count <= 1)
		return ;
	b->back = b->front;
	b->front = b->front->next;
	cmd_push("rrb", a, b, cmd);
}

void	rrr(t_HEAD *a, t_HEAD *b, t_CHEAD *cmd, t_cnt *cnt)
{
	rra(a, b, cmd, cnt);
	rrb(a, b, cmd, cnt);
}
