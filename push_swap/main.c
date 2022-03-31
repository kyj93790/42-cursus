#include "push_swap.h"

// void print_stack(t_HEAD head) {
// 	int	i;
// 	t_stack	*curr;

// 	i = 0;
// 	curr = head.front;
// 	while (i < head.count) {
// 		printf("%d\n", curr->data);
// 		curr = curr->next;
// 		i++;
// 	}
// }

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
	// 만약 인자가 하나도 없으면 -> 정렬되었다고 간주 -> 함수 종료
	if (argc < 2)
		return (0);
	parse_arg(&A, &B, argc, argv);
	// print_stack(A);
	
	// sorting 알고리즘 call
	return (0);
}