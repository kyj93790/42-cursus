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

int main(int argc, char *argv[])
{
	t_HEAD	A;
	t_HEAD	B;

	A.front = NULL;
	A.count = 0;
	A.back = NULL;
	B.front = NULL;
	B.count = 0;
	B.back = NULL;
	if (argc < 2)
		return (0);
	parse_arg(&A, &B, argc, argv);
	// printf("---------BEFORE---------\n");
	// printf("<A> : ");
	// print_stack(A);
	// printf("<B> : ");
	// print_stack(B);
	// printf("------------------------\n");
	atob(A.count, &A, &B);
	// printf("---------AFTER---------\n");
	// printf("<A> : ");
	// print_stack(A);
	// printf("<B> : ");
	// print_stack(B);
	// printf("------------------------\n");
	return (0);
}