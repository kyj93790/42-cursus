#include "push_swap.h"

void sa(t_HEAD *A, t_HEAD *B, t_CHEAD *cmd)
{
	int	temp;

	temp = A->back->data;
	A->back->data = A->back->prev->data;
	A->back->prev->data = temp;
	cmd_push("sa", A, B, cmd);
}

void sb(t_HEAD *A, t_HEAD *B, t_CHEAD *cmd)
{
	int	temp;

	temp = B->back->data;
	B->back->data = B->back->prev->data;
	B->back->prev->data = temp;
	cmd_push("sb", A, B, cmd);
}

void pa(t_HEAD *A, t_HEAD *B, t_CHEAD *cmd)
{
	int	temp;

	temp = B->back->data;
	pop_back(B);
	push_back(A, temp, B, cmd);
	cmd_push("pa", A, B, cmd);
}

void pb(t_HEAD *A, t_HEAD *B, t_CHEAD *cmd)
{
	int	temp;

	temp = A->back->data;
	pop_back(A);
	push_back(B, temp, A, cmd);
	cmd_push("pb", A, B, cmd);
}

void ra(t_HEAD *A, t_HEAD *B, t_CHEAD *cmd)
{
	if (A->count <= 1)
		return ;
	A->front = A->back;
	A->back = A->back->prev;
	cmd_push("ra", A, B, cmd);
}

void rb(t_HEAD *A, t_HEAD *B, t_CHEAD *cmd)
{
	if (B->count <= 1)
		return ;
	B->front = B->back;
	B->back = B->back->prev;
	cmd_push("rb", A, B, cmd);
}

void rra(t_HEAD *A, t_HEAD *B, t_CHEAD *cmd)
{
	if (A->count <= 1)
		return ;
	A->back = A->front;
	A->front = A->front->next;
	cmd_push("rra", A, B, cmd);
}

void rrb(t_HEAD *A, t_HEAD *B, t_CHEAD *cmd)
{
	if (B->count <= 1)
		return ;
	B->back = B->front;
	B->front = B->front->next;
	cmd_push("rrb", A, B, cmd);
}

void rrr(t_HEAD *A, t_HEAD *B, t_CHEAD *cmd)
{
	rra(A, B, cmd);
	rrb(A, B, cmd);
}