#include "push_swap.h"

void	atob(int n, t_HEAD *A, t_HEAD *B, t_command *cmd)
{
	int		i;
	t_cnt	cnt;

	if (n <= 3)
	{
		sort_pieceA(n, A, B, cmd);
		return ;
	}
	init_cnt(&cnt);
	cnt = div_atob(n, A, B, cmd);	// ra, pb, rb등을 적절하게 처리하여 분할해 줌
	i = 0;
	while (i++ < cnt.rb)
		rrr(A, B, cmd);
	i--;
	while (i++ < cnt.ra) // 이 부분 하는 게 맞는지 고민 필요
		rra(A, B, cmd);
	atob(cnt.ra, A, B, cmd);
	btoa(cnt.rb, A, B, cmd);
	btoa(cnt.pb - cnt.rb, A, B, cmd);
}

void btoa(int n, t_HEAD *A, t_HEAD *B, t_command *cmd)
{
	int		i;
	t_cnt	cnt;

	if (n <= 3)
	{
		sort_pieceB(n, A, B, cmd);
		i = 0;
		while (i++ < n)
			pa(A, B, cmd);
		return ;
	}
	init_cnt(&cnt);
	cnt = div_btoa(n, A, B, cmd);
	atob(cnt.pa-cnt.ra, A, B, cmd);
	i = 0;
	while (i++ < cnt.ra)
		rrr(A, B, cmd);
	i--;
	while (i++ < cnt.rb)
		rrb(A, B, cmd);
	atob(cnt.ra, A, B, cmd);
	btoa(cnt.rb, A, B, cmd);
}

t_cnt	div_atob(int n, t_HEAD *A, t_HEAD *B, t_command *cmd)
{
	int		pv1;
	int		pv2;
	int		i;
	int		temp;
	t_cnt	cnt;
	t_stack	*curr;

	if (getpivotA(n, A, &pv1, &pv2))
		exit_with_error(A, B);
	init_cnt(&cnt);
	i = 0;
	curr = A->back; // top부터 n개 처리
	while (i++ < n)
	{
		temp = curr->data;
		curr = curr->prev;
		if (pv1 <= temp)
		{
			ra(A, B, cmd);
			cnt.ra++;
		}
		else
		{
			pb(A, B, cmd);
			cnt.pb++;
			if (pv2 <= temp)
			{
				rb(A, B, cmd);
				cnt.rb++;
			}
		}
	}
	return (cnt);
}

t_cnt	div_btoa(int n, t_HEAD *A, t_HEAD *B, t_command *cmd)
{
	int		pv1;
	int		pv2;
	int		i;
	int		temp;
	t_cnt	cnt;
	t_stack	*curr;

	if (getpivotB(n, B, &pv1, &pv2))
		exit_with_error(A, B);
	init_cnt(&cnt);
	i = 0;
	curr = B->back;
	while (i++ < n)
	{
		temp = curr->data;
		curr = curr->prev;
		if (temp < pv2)
		{
			rb(A, B, cmd);
			cnt.rb++;
		}
		else
		{
			pa(A, B, cmd);
			cnt.pa++;
			if (temp < pv1)
			{
				ra(A, B, cmd);
				cnt.ra++;
			}
		}
	}
	return (cnt);
}