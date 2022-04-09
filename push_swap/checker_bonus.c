#include "checker_bonus.h"
 
void	exit_with_error(t_HEAD *a, t_HEAD *b, char *cmd)
{
	free_stack(a, b);
	if (cmd)
		free(cmd);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	execute_command(t_HEAD *a, t_HEAD *b, char *cmd)
{
	if (ft_strncmp(cmd, "sa", 3) == 0)
		sa(a);
	else if (ft_strncmp(cmd, "sb", 3) == 0)
		sb(b);
	else if (ft_strncmp(cmd, "ss", 3) == 0)
		ss(a, b);
	else if (ft_strncmp(cmd, "pa", 3) == 0)
		pa(a, b);
	else if (ft_strncmp(cmd, "pb", 3) == 0)
		pb(a, b);
	else if (ft_strncmp(cmd, "ra", 3) == 0)
		ra(a);
	else if (ft_strncmp(cmd, "rb", 3) == 0)
		rb(b);
	else if (ft_strncmp(cmd, "rr", 3) == 0)
		rr(a, b);
	else if (ft_strncmp(cmd, "rra", 4) == 0)
		rra(a);
	else if (ft_strncmp(cmd, "rrb", 4) == 0)
		rrb(b);
	else if (ft_strncmp(cmd, "rrr", 4) == 0)
		rrr(a, b);
	else
		exit_with_error(a, b, cmd);
}

int	check_correction(t_HEAD a, t_HEAD b)
{
	t_stack	*curr;
	int		temp;
	int		i;

	if (b.count != 0)
		return (0);
	curr = a.back;
	temp = curr->data;
	i = 1;
	while (i < a.count)
	{
		curr = curr->prev;
		if (curr->data < temp)
			return (0);
		temp = curr->data;
		i++;
	}
	return (1);
}

void	get_commands(t_HEAD *a, t_HEAD *b)
{
	char	*curr;
	int		len;

	while (1)	
	{
		curr = get_next_line(0);
		if (curr == 0)
			break ;
		len = ft_strlen(curr);
		curr[len-1] = '\0';
		execute_command(a, b, curr);
		free(curr);
	}
}

int main(int argc, char *argv[])
{
	t_HEAD	a;
	t_HEAD	b;

	if (argc < 2)
		return (0);
	parse_arg(&a, &b, argc, argv);
	get_commands(&a, &b);
	if (check_correction(a, b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack(&a, &b);
	return (0);
}