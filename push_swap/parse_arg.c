#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (*(s + i))
		i++;
	return (i);
}

// 0이면 에러를 뜻함. 어차피 0이 들어올 수 없음. 문제 조건에서 !
int	arg_to_int(char *arg)
{
	size_t	len;
	size_t	i;
	t_ll	result;
	int		neg;
	
	len = ft_strlen(arg);
	i = 0;
	neg = 1;
	if (arg[i] == '-')
	{
		neg = -1;
		i++;
	}
	result = 0;
	while (i < len)
	{
		if (arg[i] < '0' || '9' < arg[i])
			return (0);
		result = result * 10 + (arg[i++] - '0');
	}
	result *= neg;
	if (result < INT_MIN || result > INT_MAX)
		return (0);
	return ((int)result);
}

int	check_dup(t_HEAD *A, int data) {
	int		i;
	t_stack	*curr;

	i = 0;
	curr = A->front;
	while (i < A->count) {
		if (data == curr->data)
			return (1);
		i++;
	}
	return (0);
}

void	parse_arg(t_HEAD *A, t_HEAD *B, int argc, char *argv[])
{
	int	i;
	int	data;

	i = 1;
	while (i < argc)
	{
		data = arg_to_int(argv[i]);
		if (data == 0 || check_dup(A, data))
		{ // error
			free_stack(A, B);
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		push_front(A, data, B);
		i++;
	}
}