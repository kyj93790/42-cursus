#include "push_swap.h"

void	atob(int n, t_HEAD *A, t_HEAD *B)
{
	int		i;
	t_cnt	cnt;

	if (n <= 3)
	{
		sort_pieceA(n, A);
		return ;
	}
	init_cnt(&cnt);
	cnt = div_atob(n, A, B);	// ra, pb, rb등을 적절하게 처리하여 분할해 줌
	i = 0;
	while (i++ < cnt.rb)
		rrr(A, B);
	i--;
	while (i++ < cnt.ra) // 이 부분 하는 게 맞는지 고민 필요
		rrx('A', A);
	atob(cnt.ra, A, B);
	btoa(cnt.rb, A, B);
	btoa(cnt.pb - cnt.rb, A, B);
}

void btoa(int n, t_HEAD *A, t_HEAD *B)
{
	int		i;
	t_cnt	cnt;

	if (n <= 3)
	{
		sort_pieceB(n, B);
		i = 0;
		while (i++ < n)
			px('A', A, B);
		return ;
	}
	init_cnt(&cnt);
	cnt = div_btoa(n, A, B);
	atob(cnt.pa-cnt.ra, A, B);
	i = 0;
	while (i++ < cnt.ra)
		rrr(A, B);
	i--;
	while (i++ < cnt.rb)
		rrx('B', B);
	atob(cnt.ra, A, B);
	btoa(cnt.rb, A, B);
}

t_cnt	div_atob(int n, t_HEAD *A, t_HEAD *B)
{
	int		pv1;
	int		pv2;
	int		i;
	int		temp;
	t_cnt	cnt;
	t_stack	*curr;

	getpivotA(n, A, &pv1, &pv2);
	init_cnt(&cnt);
	i = 0;
	curr = A->back; // top부터 n개 처리
	while (i++ < n)
	{
		temp = curr->data;
		curr = curr->prev;
		if (pv1 <= temp)
		{
			rx('A', A);
			cnt.ra++;
		}
		else
		{
			px('B', B, A);
			cnt.pb++;
			if (pv2 <= temp)
			{
				rx('B', B);
				cnt.rb++;
			}
		}
	}
	return (cnt);
}

t_cnt	div_btoa(int n, t_HEAD *A, t_HEAD *B)
{
	int		pv1;
	int		pv2;
	int		i;
	int		temp;
	t_cnt	cnt;
	t_stack	*curr;

	getpivotB(n, B, &pv1, &pv2);
	init_cnt(&cnt);
	i = 0;
	curr = B->back;
	while (i++ < n)
	{
		temp = curr->data;
		curr = curr->prev;
		if (temp < pv2)
		{
			rx('B', B);
			cnt.rb++;
		}
		else
		{
			px('A', A, B);
			cnt.pa++;
			if (temp < pv1)
			{
				rx('A', A);
				cnt.ra++;
			}
		}
	}
	return (cnt);
}