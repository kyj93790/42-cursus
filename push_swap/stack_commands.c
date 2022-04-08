#include "push_swap.h"

void sa(t_HEAD *A, t_HEAD *B, t_command *cmd)
{
	int	temp;

	temp = A->back->data;
	A->back->data = A->back->prev->data;
	A->back->prev->data = temp;
}

void sb(t_HEAD *A, t_HEAD *B, t_command *cmd)
{
	int	temp;

	temp = B->back->data;
	B->back->data = B->back->prev->data;
	B->back->prev->data = temp;
}

void pa(t_HEAD *A, t_HEAD *B, t_command *cmd)
{
	int	temp;

	temp = B->back->data;
	pop_back(B);
	push_back(A, temp, B);
}

void pb(t_HEAD *A, t_HEAD *B, t_command *cmd)
{
	int	temp;

	temp = A->back->data;
	pop_back(A);
	push_back(B, temp, A);
}

void ra(t_HEAD *A, t_HEAD *B, t_command *cmd)
{
	A->front = A->back;
	A->back = A->back->prev;
}

void rb(t_HEAD *A, t_HEAD *B, t_command *cmd)
{
	B->front = B->back;
	B->back = B->back->prev;
}

void rra(t_HEAD *A, t_HEAD *B, t_command *cmd)
{
	A->back = A->front;
	A->front = A->front->next;
}

void rrb(t_HEAD *A, t_HEAD *B, t_command *cmd)
{
	B->back = B->front;
	B->front = B->front->next;
}

void rrr(t_HEAD *A, t_HEAD *B, t_command *cmd)
{
	rra(A, cmd);
	rrb(B, cmd);
}