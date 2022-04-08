#include "push_swap.h"

void sx(char op, t_HEAD *x)
{
	// swap x
	int	temp;

	temp = x->back->data;
	x->back->data = x->back->prev->data;
	x->back->prev->data = temp;
	if (op == 'A')
		ft_printf("sa\n");
	else if (op == 'B')
		ft_printf("sb\n");
}

void px(char op, t_HEAD *x, t_HEAD *y)
{
	// push x (y->x로 push)
	int	temp;

	temp = y->back->data;
	pop_back(y);
	push_back(x, temp, y);
	if (op == 'A')
		ft_printf("pa\n");
	else if (op == 'B')
		ft_printf("pb\n");
}

void rx(char op, t_HEAD *x)
{
	// rotate x (top 방향으로 한 칸씩)
	x->front = x->back;
	x->back = x->back->prev;
	if (op == 'A')
		ft_printf("ra\n");
	else if (op == 'B')
		ft_printf("rb\n");
}

void rrx(char op, t_HEAD *x)
{
	// reverse rotate x
	x->back = x->front;
	x->front = x->front->next;
	if (op == 'A')
		ft_printf("rra\n");
	else if (op == 'B')
		ft_printf("rrb\n");
}

void rrr(t_HEAD *x, t_HEAD *y)
{
	rrx(0, x);
	rrx(0, y);
	ft_printf("rrr\n");
}