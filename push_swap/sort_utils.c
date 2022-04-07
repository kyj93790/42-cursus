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
void	getpivotA(int n, t_HEAD *head, int *pv1, int *pv2)
{
	int		*temp;
	t_stack	*curr;
	int		i;

	temp = malloc(sizeof(int) * n);
	curr = head->back;
	i = 0;
	while (i < n)
	{
		temp[i++] = curr->data;
		curr = curr->prev;
	}
	bubble_sort(n, temp);
	*pv1 = temp[n/2];
	*pv2 = temp[n/2/2];
	free(temp);
}

void	getpivotB(int n, t_HEAD *head, int *pv1, int *pv2)
{
	int		*temp;
	t_stack	*curr;
	int		i;

	temp = malloc(sizeof(int) * n);
	curr = head->back;
	i = 0;
	while (i < n)
	{
		temp[i++] = curr->data;
		curr = curr->prev;
	}
	bubble_sort(n, temp);
	*pv1 = temp[n/2 + n/2/2];
	*pv2 = temp[n/2];
	free(temp);
}

// 3개 이하인 case에 대해서 정렬해주는 알고리즘
void	sort_pieceA(int n, t_HEAD *A)
{
	if (n == 1)
		return ;
	if (n == 2 && A->back->prev->data < A->back->data)
		sx(A);
	else if (n == 3)
	{
		if (A->back->prev->prev->data < A->back->prev->data && A->back->data < A->back->prev->data) // 두번째가 제일 큼
		{
			if (A->count != 3)
			{
				rx(A);
				sx(A);
			}
			rrx(A);
		}
		else if (A->back->prev->prev->data < A->back->data && A->back->prev->data < A->back->data) // 3번째가 제일 큼
		{
			if (A->count == 3)
				rx(A);
			else
			{
				sx(A);
				rx(A);
				sx(A);
				rrx(A);
			}
		}
		if (A->back->prev->data < A->back->data)
			sx(A);
	}
}

void	sort_pieceB(int n, t_HEAD *B)
{
	if (n == 1)
		return ;
	if (n == 2 && B->back->prev->data > B->back->data)
		sx(B);
	else if (n == 3)
	{
		if (B->back->prev->data < B->back->prev->prev->data && B->back->prev->data < B->back->data) // 두번째가 제일 작음
		{
			if (B->count != 3)
			{
				rx(B);
				sx(B);
			}
			rrx(B);
		}
		else if (B->back->data < B->back->prev->prev->data && B->back->data < B->back->prev->data) // 세번째가 제일 작음
		{
			if (B->count == 3)
				rx(B);
			else
			{
				sx(B);
				rx(B);
				sx(B);
				rrx(B);
			}
		}
		if (B->back->prev->data > B->back->data)
			sx(B);
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