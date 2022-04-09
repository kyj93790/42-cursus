/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 02:03:27 by yejin             #+#    #+#             */
/*   Updated: 2022/04/10 02:04:49 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (result < -2147483648 || result > 2147483647)
		return (0);
	return ((int)result);
}

int	check_arg_error(char *arg)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(arg);
	i = 0;
	if (arg[i] == '-' || arg[i] == '+')
	{
		if (arg[i + 1] < '0' || '9' < arg[i + 1])
			return (1);
		i++;
	}
	while (i < len)
	{
		if (arg[i] < '0' || '9' < arg[i])
			return (1);
		i++;
	}
	return (0);
}

int	check_dup(t_HEAD *a, int data)
{
	int		i;
	t_stack	*curr;

	i = 0;
	curr = a->front;
	while (i < a->count)
	{
		if (data == curr->data)
			return (1);
		curr = curr->next;
		i++;
	}
	return (0);
}

void	parse_arg(t_HEAD *a, t_HEAD *b, int argc, char *argv[])
{
	int		i;
	int		j;
	int		data;
	char	**result;

	i = 0;
	while (++i < argc)
	{
		result = ft_split(argv[i], ' ');
		if (result == 0)
			exit_with_error(a, b, 0);
		j = -1;
		while (result[++j])
		{
			data = arg_to_int(result[j]);
			if (check_arg_error(result[j]) || check_dup(a, data))
				exit_with_error(a, b, 0);
			push_front(a, data, b, 0);
		}
		j = 0;
		while (result[j])
			free(result[j++]);
		free(result);
	}
}
