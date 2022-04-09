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

int	getpivot_a(int n, t_HEAD *head, int *pv1, int *pv2)
{
	int		*temp;
	t_stack	*curr;
	int		i;

	temp = malloc(sizeof(int) * n);
	if (temp == 0)
		return (0);
	curr = head->back;
	i = 0;
	while (i < n)
	{
		temp[i++] = curr->data;
		curr = curr->prev;
	}
	bubble_sort(n, temp);
	*pv1 = temp[n / 2];
	*pv2 = temp[n / 2 / 2];
	free(temp);
	return (1);
}

int	getpivot_b(int n, t_HEAD *head, int *pv1, int *pv2)
{
	int		*temp;
	t_stack	*curr;
	int		i;

	temp = malloc(sizeof(int) * n);
	if (temp == 0)
		return (0);
	curr = head->back;
	i = 0;
	while (i < n)
	{
		temp[i++] = curr->data;
		curr = curr->prev;
	}
	bubble_sort(n, temp);
	*pv1 = temp[n / 2 + n / 2 / 2];
	*pv2 = temp[n / 2];
	free(temp);
	return (1);
}

void	init_cnt(t_cnt *cnt)
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
