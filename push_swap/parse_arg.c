#include "push_swap.h"

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
	if (arg[i] == '-' || arg[i] == '+')
	{
		if (arg[i] == '-')
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
		curr = curr->next;
		i++;
	}
	return (0);
}

void	parse_arg(t_HEAD *A, t_HEAD *B, int argc, char *argv[])
{
	int		i;
	int		j;
	int		data;
	char	**result;

	i = 1;
	while (i < argc)
	{
		result = ft_split(argv[i], ' ');
		if (result == 0)
			exit_with_error(A, B, 0);
		j = 0;
		while (result[j])
		{
			data = arg_to_int(result[j]);
			if (data == 0 || check_dup(A, data)) // 중복체크 제대로 안되고 있음.
				exit_with_error(A, B, 0);
			j++;
			push_front(A, data, B, 0);
		}
		j = 0;
		while (result[j])
			free(result[j++]);
		free(result);
		i++;
	}
}