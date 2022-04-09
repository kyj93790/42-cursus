#include "checker_bonus.h"

void	sa(t_HEAD *a)
{
	int	temp;

	temp = a->back->data;
	a->back->data = a->back->prev->data;
	a->back->prev->data = temp;
}

void	sb(t_HEAD *b)
{
	int	temp;

	temp = b->back->data;
	b->back->data = b->back->prev->data;
	b->back->prev->data = temp;
}

void	pa(t_HEAD *a, t_HEAD *b)
{
	int	temp;

	temp = b->back->data;
	pop_back(b);
	push_back(a, temp, b);
}

void	pb(t_HEAD *a, t_HEAD *b)
{
	int	temp;

	temp = a->back->data;
	pop_back(a);
	push_back(b, temp, a);
}
