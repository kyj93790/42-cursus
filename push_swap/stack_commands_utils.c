#include "push_swap.h"

void	push_front(t_HEAD *head, int data, t_HEAD *another, t_CHEAD *cmd)
{
	t_stack	*pnew;

	pnew = (t_stack *)malloc(sizeof(t_stack));
	if (pnew == 0)
		exit_with_error(head, another, cmd);
	pnew->data = data;
	if (head->count == 0)
	{
		pnew->prev = pnew;
		pnew->next = pnew;
		head->front = pnew;
		head->back = pnew;
	}
	else
	{
		pnew->next = head->front;
		pnew->next->prev = pnew;
		head->front = pnew;
		pnew->prev = head->back;
		head->back->next = pnew;
	}
	(head->count)++;
}

void	push_back(t_HEAD *head, int data, t_HEAD *another, t_CHEAD *cmd)
{
	t_stack	*pnew;

	pnew = (t_stack *)malloc(sizeof(t_stack));
	if (pnew == 0)
		exit_with_error(head, another, cmd);
	pnew->data = data;
	if (head->count == 0)
	{
		pnew->prev = pnew;
		pnew->next = pnew;
		head->front = pnew;
		head->back = pnew;
	}
	else
	{
		pnew->prev = head->back;
		pnew->prev->next = pnew;
		head->back = pnew;
		pnew->next = head->front;
		head->front->prev = pnew;
	}
	(head->count)++;
}

void	pop_front(t_HEAD *head)
{
	t_stack	*pCur;
	
	if (head->count == 0)
		return ;
	pCur = head->front;
	head->front = pCur->next;
	head->front->prev = head->back;
	head->back->next = head->front;
	free(pCur);
	(head->count)--;
}

void	pop_back(t_HEAD *head)
{
	t_stack	*pCur;
	
	if (head->count == 0)
		return ;
	pCur = head->back;
	head->back = pCur->prev;
	head->back->next = head->front;
	head->front->prev = head->back;
	free(pCur);
	(head->count)--;
}

void free_stack(t_HEAD *stack1, t_HEAD *stack2)
{
	while (stack1->count)
		pop_front(stack1);
	while (stack2->count)
		pop_front(stack2);
}