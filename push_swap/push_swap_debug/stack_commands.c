#include "push_swap.h"

void sx(t_HEAD *x)
{
	// swap x
	int	temp;

	temp = x->back->data;
	x->back->data = x->back->prev->data;
	x->back->prev->data = temp;
}

void px(t_HEAD *x, t_HEAD *y)
{
	// push x (y->x로 push)
	int	temp;

	temp = y->back->data;
	pop_back(y);
	push_back(x, temp, y);
}

void rx(t_HEAD *x)
{
	// rotate x (top 방향으로 한 칸씩)
	x->front = x->back;
	x->back = x->back->prev;
}

void rrx(t_HEAD *x)
{
	// reverse rotate x
	x->back = x->front;
	x->front = x->front->next;
}

void rrr(t_HEAD *x, t_HEAD *y)
{
	rrx(x);
	rrx(y);
}