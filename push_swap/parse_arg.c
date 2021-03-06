/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 02:03:27 by yejin             #+#    #+#             */
/*   Updated: 2022/04/11 21:24:24 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_ll	arg_to_int(t_HEAD *a, t_HEAD *b, char *arg)
{
	size_t	len;
	size_t	i;
	t_ll	result;
	int		neg;

	if (check_arg_error(arg))
		exit_with_error(a, b, 0);
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
	while (i < len && result < 10000000000)
		result = result * 10 + (arg[i++] - '0');
	result *= neg;
	return (result);
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
	t_ll	data;
	char	**result;

	i = 0;
	while (++i < argc)
	{
		result = ft_split(argv[i], ' ');
		if (result == 0 || result[0] == 0)
			exit_with_error(a, b, 0);
		j = -1;
		while (result[++j])
		{
			data = arg_to_int(a, b, result[j]);
			if (data < -2147483648 || data > 2147483647 || check_dup(a, data))
				exit_with_error(a, b, 0);
			push_front(a, (int)data, b, 0);
		}
		j = 0;
		while (result[j])
			free(result[j++]);
		free(result);
	}
}
