#include "push_swap.h"

void	bubble_sort(int n, int *arr)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < n - 1)
	{
		j = i + 1;
		while (j < n)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
			j++;
		}
		i++;
	}
}

// 현 stack에서 top부터 n개의 수를 정렬할 때 적절한 pivot 설정
void	getpivot(int n, t_HEAD *head, int *pv1, int *pv2)
{
	int		*temp;
	t_stack	*curr;
	int		i;
	int		j;

	temp = malloc(sizeof(int) * n);
	curr = head->front;
	i = 0;
	while (curr)
	{
		temp[i++] = curr->data;
		curr = curr->next;
	}
	bubble_sort(n, temp);
	*pv1 = temp[n/2];
	*pv2 = temp[n/2/2];
	free(temp);
}

// 3개 이하인 case에 대해서 정렬해주는 알고리즘
void	sort_pieceA(int n, t_HEAD *A)
{
	int a;
	int	b;
	int	c;
	// top의 3개를 정렬 (3 2 1 순으로) // 가장 큰 수를 아래로 배치하고 sA여부 판단
	if (n == 1)
		return ;
	c = A->back->data;
	b = A->back->prev->data;
	if (n == 2 && b < c)
		sx(A);
	else if (n == 3)
	{
		a = A->back->prev->prev->data;
		if (a < b && c < b) // 두번째가 제일 큼
			rrx(A);
		else if (a < c && b < c) // 3번째가 제일 큼
			rx(A);
		if (b < c)
			sx(A);
	}
}

void	sort_pieceB(int n, t_HEAD *A, t_HEAD *B)
{
	int a;
	int	b;
	int	c;

	if (n == 1)
		return ;
	c = B->back->data;
	b = B->back->prev->data;
	if (n == 2 && b > c)
		sx(B);
	else if (n == 3)
	{
		a = B->back->prev->prev->data;
		if (b < a && b < c) // 두번째가 제일 작음
			rrx(B);
		else if (c < a && c < b) // 세번째가 제일 작음
			rx(A);
		if (b > c)
			sx(A);
	}
}

void init_cnt(t_cnt *cnt)
{
	cnt->sa = 0;
	cnt->sb = 0;
	cnt->ss = 0;
	cnt->pa = 0;
	cnt->pb = 0;
	cnt->ra = 0;
	cnt->rb = 0;
	cnt->rr = 0;
	cnt->rra = 0;
	cnt->rrb = 0;
	cnt->rrr = 0;
}