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
	// rrr ra 처리
	i = 0;
	while (i++ < cnt.rb)
		rrr(A, B);
	while (i++ < cnt.ra) // 이 부분 하는 게 맞는지 고민 필요
		rrx(A);
	atob(cnt.ra, A, B);
	btoa(cnt.rb, A, B);
	btoa(cnt.pb-cnt.rb, A, B);
}

void btoa(int n, t_HEAD *A, t_HEAD *B)
{
	int		i;
	t_cnt	cnt;

	if (n <= 3)
	{
		sort_pieceB(n, A, B);	// B에 대해서는 A와 반대로(역순) 정렬해야 하므로 이를 다른 정렬 알고리즘으로 구현
		i = 0;
		while (i < n)
			px(A, B);
		return ;
	}
	init_cnt(&cnt);
	cnt = div_btoa(n, A, B);
	atob(cnt.pa-cnt.ra, A, B);
	/// rrr rb 처리  
	i = 0;
	while (i++ < cnt.ra)
		rrr(A, B);
	while (i++ < cnt.rb)
		rrx(B);
	atob(cnt.ra, A, B);
	btoa(cnt.rb, A, B);
}

t_cnt	div_atob(int n, t_HEAD *A, t_HEAD *B)
{
	int		pv1;
	int		pv2;
	int		i;
	t_cnt	cnt;
	t_stack	*curr;

	getpivot(n, B, &pv1, &pv2);
	init_cnt(&cnt);
	i = 0;
	curr = A->back; // top부터 n개 처리
	while (i++ < n)
	{
		if (pv1 <= curr->data)
		{
			rx(A);
			cnt.ra++;
		}
		else
		{
			px(B, A);
			cnt.pb++;
			if (pv2 <= curr->data)
			{
				rx(B);
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
	t_cnt	cnt;
	t_stack	*curr;

	getpivot(n, B, &pv1, &pv2);
	init_cnt(&cnt);
	i = 0;
	curr = B->back;
	while (i++ < n)
	{
		if (curr->data < pv1)
		{
			rx(B);
			cnt.rb++;
		}
		else
		{
			px(A, B);
			cnt.pa++;
			if (curr->data < pv2)
			{
				rx(A);
				cnt.ra++;
			}
		}
	}
	return (cnt);
	// pv2>x : rb
	// pv2<=x<pv1 : pa, ra
	// pv1<=x : pa
	// atob(pa-ra) : a에 위에 추가한 것(정렬안된 것 중에 가장 큰 것) 정렬하기
	// ra해줬던(a에서 아래로 내려가 있는) 항목들 끌어올려주고 그 친구들도 atob(ra)
}