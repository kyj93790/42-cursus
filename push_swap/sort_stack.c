#include "push_swap.h"

void	atob(int n, t_HEAD *A, t_HEAD *B, t_CHEAD *cmd)
{
	int		i;
	t_cnt	cnt;

	if (n <= 3)
	{
		sort_pieceA(n, A, B, cmd);
		return ;
	}
	init_cnt(&cnt);
	cnt = div_atob(n, A, B, cmd);
	i = 0;
	while (i++ < cnt.rb)
        rrr(A, B, cmd, 0);
    i--;
	if (n/2 != A->count)
	{
		while (i++ < cnt.ra)
			rra(A, B, cmd, 0);
	}
	atob(cnt.ra, A, B, cmd);
	btoa(cnt.rb, A, B, cmd);
	btoa(cnt.pb - cnt.rb, A, B, cmd);
}

void btoa(int n, t_HEAD *A, t_HEAD *B, t_CHEAD *cmd)
{
	int		i;
	t_cnt	cnt;

	if (n <= 3)
	{
		sort_pieceB(n, A, B, cmd);
		i = 0;
		while (i++ < n)
			pa(A, B, cmd, 0);
		return ;
	}
	init_cnt(&cnt);
	cnt = div_btoa(n, A, B, cmd);
	atob(cnt.pa-cnt.ra, A, B, cmd);
	i = 0;
	while (i++ < cnt.ra)
		rrr(A, B, cmd, 0);
	i--;
	while (i++ < cnt.rb)
		rrb(A, B, cmd, 0);
	atob(cnt.ra, A, B, cmd);
	btoa(cnt.rb, A, B, cmd);
}

t_cnt	div_atob(int n, t_HEAD *A, t_HEAD *B, t_CHEAD *cmd)
{
	int		pv1;
	int		pv2;
	int		i;
	int		temp;
	t_cnt	cnt;
	t_stack	*curr;

	if (getpivotA(n, A, &pv1, &pv2) == 0)
		exit_with_error(A, B, cmd);
	init_cnt(&cnt);
	i = 0;
	curr = A->back; // top부터 n개 처리
	while (i++ < n)
	{
		temp = curr->data;
		curr = curr->prev;
		if (pv1 <= temp)
			ra(A, B, cmd, &cnt);
		else
		{
			pb(A, B, cmd, &cnt);
			if (pv2 <= temp)
				rb(A, B, cmd, &cnt);
		}
	}
	return (cnt);
}

t_cnt	div_btoa(int n, t_HEAD *A, t_HEAD *B, t_CHEAD *cmd)
{
	int		pv1;
	int		pv2;
	int		i;
	int		temp;
	t_cnt	cnt;
	t_stack	*curr;

	if (getpivotB(n, B, &pv1, &pv2) == 0)
		exit_with_error(A, B, cmd);
	init_cnt(&cnt);
	i = 0;
	curr = B->back;
	while (i++ < n)
	{
		temp = curr->data;
		curr = curr->prev;
		if (temp < pv2)
			rb(A, B, cmd, &cnt);
		else
		{
			pa(A, B, cmd, &cnt);
			if (temp < pv1)
				ra(A, B, cmd, &cnt);
		}
	}
	return (cnt);
}