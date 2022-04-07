#include "push_swap.h"

void print_stack(t_HEAD head) {
	int	i;
	t_stack	*curr;

	i = 0;
	curr = head.front;
	while (i < head.count) {
		ft_printf("%d\n", curr->data);
		curr = curr->next;
		i++;
	}
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
	atob(A.count, &A, &B);
	return (0);
}