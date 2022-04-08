#include "push_swap.h"

void print_stack(t_HEAD head) {
	int	i;
	t_stack	*curr;

	i = 0;
	curr = head.front;
	while (i < head.count) {
		printf("%2d ", curr->data);
		curr = curr->next;
		i++;
	}
	printf("\n");
}

void exit_with_error(t_HEAD *A, t_HEAD *B, t_CHEAD *cmd)
{
	free_stack(A, B);
	free_cmd(cmd);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void init(t_HEAD *A, t_HEAD *B, t_CHEAD *cmd)
{
	A->front = NULL;
	A->count = 0;
	A->back = NULL;
	B->front = NULL;
	B->count = 0;
	B->back = NULL;
	cmd->front = NULL;
	cmd->count = 0;
	cmd->back = NULL;
}

int main(int argc, char *argv[])
{
	t_HEAD		A;
	t_HEAD		B;
	t_CHEAD		cmd;

	init(&A, &B, &cmd);
	if (argc < 2)
		return (0);
	parse_arg(&A, &B, argc, argv);
	if (4 <= A.count && A.count <= 6)
	{
		div_atob(A.count, &A, &B, &cmd);
		atob(A.count, &A, &B, &cmd);
		btoa(B.count, &A, &B, &cmd);
	}
	else
		atob(A.count, &A, &B, &cmd);
	print_cmd(cmd);
	free_stack(&A, &B);
	free_cmd(&cmd);
	return (0);
}