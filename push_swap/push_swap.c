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

void exit_with_error(t_HEAD *A, t_HEAD *B)
{
	free_stack(A, B);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
	t_HEAD		A;
	t_HEAD		B;
	t_command	*cmd;

	A.front = NULL;
	A.count = 0;
	A.back = NULL;
	B.front = NULL;
	B.count = 0;
	B.back = NULL;
	cmd = NULL;
	if (argc < 2)
		return (0);
	parse_arg(&A, &B, argc, argv);
	atob(A.count, &A, &B, cmd);
	return (0);
}