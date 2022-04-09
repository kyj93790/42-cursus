#include "push_swap.h"

void	sa(t_HEAD *a, t_HEAD *b, t_CHEAD *cmd, t_cnt *cnt)
{
	int	temp;

	if (cnt)
		(cnt->sa)++;
	temp = a->back->data;
	a->back->data = a->back->prev->data;
	a->back->prev->data = temp;
	cmd_push("sa", a, b, cmd);
}

void	sb(t_HEAD *a, t_HEAD *b, t_CHEAD *cmd, t_cnt *cnt)
{
	int	temp;

	if (cnt)
		(cnt->sb)++;
	temp = b->back->data;
	b->back->data = b->back->prev->data;
	b->back->prev->data = temp;
	cmd_push("sb", a, b, cmd);
}

void	pa(t_HEAD *a, t_HEAD *b, t_CHEAD *cmd, t_cnt *cnt)
{
	int	temp;

	if (cnt)
		(cnt->pa)++;
	temp = b->back->data;
	pop_back(b);
	push_back(a, temp, b, cmd);
	cmd_push("pa", a, b, cmd);
}

void	pb(t_HEAD *a, t_HEAD *b, t_CHEAD *cmd, t_cnt *cnt)
{
	int	temp;

	if (cnt)
		(cnt->pb)++;
	temp = a->back->data;
	pop_back(a);
	push_back(b, temp, a, cmd);
	cmd_push("pb", a, b, cmd);
}
