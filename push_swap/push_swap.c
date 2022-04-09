#include "push_swap.h"

void	exit_with_error(t_HEAD *a, t_HEAD *b, t_CHEAD *cmd)
{
	free_stack(a, b);
	free_cmd(cmd);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	init(t_HEAD *a, t_HEAD *b, t_CHEAD *cmd)
{
	a->front = NULL;
	a->count = 0;
	a->back = NULL;
	b->front = NULL;
	b->count = 0;
	b->back = NULL;
	cmd->front = NULL;
	cmd->count = 0;
	cmd->back = NULL;
}

void	print_cmd(t_CHEAD cmd)
{
	t_command	*curr;
	int			i;

	i = 0;
	curr = cmd.front;
	while (i < cmd.count)
	{
		ft_printf("%s\n", curr->data);
		curr = curr->next;
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_HEAD		a;
	t_HEAD		b;
	t_CHEAD		cmd;

	init(&a, &b, &cmd);
	if (argc < 2)
		return (0);
	parse_arg(&a, &b, argc, argv);
	if (4 <= a.count && a.count <= 6)
	{
		div_atob(a.count, &a, &b, &cmd);
		atob(a.count, &a, &b, &cmd);
		btoa(b.count, &a, &b, &cmd);
	}
	else
		atob(a.count, &a, &b, &cmd);
	print_cmd(cmd);
	free_stack(&a, &b);
	free_cmd(&cmd);
	return (0);
}
