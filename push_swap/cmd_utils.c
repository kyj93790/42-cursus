#include "push_swap.h"

int	check_merge(char *s, t_CHEAD *cmd)
{
	char	*temp;

	if (cmd->count == 0)
		return (0);
	temp = cmd->back->data;
	if ((ft_strncmp(s, "ra", 3) == 0 && ft_strncmp(temp, "rb", 3) == 0) || \
		(ft_strncmp(s, "rb", 3) == 0 && ft_strncmp(temp, "ra", 3) == 0))
	{
		cmd->back->data = "rr";
		return (1);
	}
	else if ((ft_strncmp(s, "sa", 3) == 0 && ft_strncmp(temp, "sb", 3) == 0) || \
			(ft_strncmp(s, "sb", 3) == 0 && ft_strncmp(temp, "sa", 3) == 0))
	{
		cmd->back->data = "ss";
		return (1);
	}
	else if ((ft_strncmp(s, "rra", 4) == 0 && ft_strncmp(temp, "rrb", 4) == 0) || \
			(ft_strncmp(s, "rrb", 4) == 0 && ft_strncmp(temp, "rra", 4) == 0))
	{
		cmd->back->data = "rrr";
		return (1);
	}
	return (0);
}

int	check_pop(char *s, t_CHEAD *cmd)
{
	
}

void	cmd_push(char *s, t_HEAD *A, t_HEAD *B, t_CHEAD *cmd)
{
	t_command	*pnew;

	if (check_merge(s, cmd))
		return ;
	pnew = (t_command *)malloc(sizeof(t_command));
	if (pnew == 0)
		exit_with_error(A, B, cmd);
	pnew->data = s;
	pnew->next = NULL;
	if (cmd->count == 0)
	{
		cmd->front = pnew;
		cmd->back = pnew;
	}
	else
	{
		cmd->back->next = pnew;
		cmd->back = pnew;
	}
	(cmd->count)++;
}

void	free_cmd(t_CHEAD *cmd)
{
	t_command	*curr;
	t_command	*pcur;

	if (cmd == 0)
		return ;
	curr = cmd->front;
	while (curr)
	{
		pcur = curr;
		curr = pcur->next;
		free(pcur);
	}
	return ;
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
