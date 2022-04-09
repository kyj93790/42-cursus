/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 02:03:41 by yejin             #+#    #+#             */
/*   Updated: 2022/04/10 02:04:54 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	atob(int n, t_HEAD *a, t_HEAD *b, t_CHEAD *cmd)
{
	int		i;
	t_cnt	cnt;

	if (n <= 3)
	{
		sort_piece_a(n, a, b, cmd);
		return ;
	}
	init_cnt(&cnt);
	cnt = div_atob(n, a, b, cmd);
	i = 0;
	while (i++ < cnt.rb)
		rrr(a, b, cmd, 0);
	i--;
	if (n / 2 != a->count)
	{
		while (i++ < cnt.ra)
			rra(a, b, cmd, 0);
	}
	atob(cnt.ra, a, b, cmd);
	btoa(cnt.rb, a, b, cmd);
	btoa(cnt.pb - cnt.rb, a, b, cmd);
}

void	btoa(int n, t_HEAD *a, t_HEAD *b, t_CHEAD *cmd)
{
	int		i;
	t_cnt	cnt;

	if (n <= 3)
	{
		sort_piece_b(n, a, b, cmd);
		i = 0;
		while (i++ < n)
			pa(a, b, cmd, 0);
		return ;
	}
	init_cnt(&cnt);
	cnt = div_btoa(n, a, b, cmd);
	atob(cnt.pa - cnt.ra, a, b, cmd);
	i = 0;
	while (i++ < cnt.ra)
		rrr(a, b, cmd, 0);
	i--;
	while (i++ < cnt.rb)
		rrb(a, b, cmd, 0);
	atob(cnt.ra, a, b, cmd);
	btoa(cnt.rb, a, b, cmd);
}

t_cnt	div_atob(int n, t_HEAD *a, t_HEAD *b, t_CHEAD *cmd)
{
	int		pv1;
	int		pv2;
	int		temp;
	t_cnt	cnt;
	t_stack	*curr;

	if (getpivot_a(n, a, &pv1, &pv2) == 0)
		exit_with_error(a, b, cmd);
	init_cnt(&cnt);
	curr = a->back;
	while (n--)
	{
		temp = curr->data;
		curr = curr->prev;
		if (pv1 <= temp)
			ra(a, b, cmd, &cnt);
		else
		{
			pb(a, b, cmd, &cnt);
			if (pv2 <= temp)
				rb(a, b, cmd, &cnt);
		}
	}
	return (cnt);
}

t_cnt	div_btoa(int n, t_HEAD *a, t_HEAD *b, t_CHEAD *cmd)
{
	int		pv1;
	int		pv2;
	int		temp;
	t_cnt	cnt;
	t_stack	*curr;

	if (getpivot_b(n, b, &pv1, &pv2) == 0)
		exit_with_error(a, b, cmd);
	init_cnt(&cnt);
	curr = b->back;
	while (n--)
	{
		temp = curr->data;
		curr = curr->prev;
		if (temp < pv2)
			rb(a, b, cmd, &cnt);
		else
		{
			pa(a, b, cmd, &cnt);
			if (temp < pv1)
				ra(a, b, cmd, &cnt);
		}
	}
	return (cnt);
}
