#include "checker_bonus.h"

void	ra(t_HEAD *a)
{
	if (a->count <= 1)
		return ;
	a->front = a->back;
	a->back = a->back->prev;
}

void	rb(t_HEAD *b)
{
	if (b->count <= 1)
		return ;
	b->front = b->back;
	b->back = b->back->prev;
}

void	rra(t_HEAD *a)
{
	if (a->count <= 1)
		return ;
	a->back = a->front;
	a->front = a->front->next;
}

void	rrb(t_HEAD *b)
{
	if (b->count <= 1)
		return ;
	b->back = b->front;
	b->front = b->front->next;
}
