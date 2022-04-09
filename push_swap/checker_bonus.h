/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 02:03:08 by yejin             #+#    #+#             */
/*   Updated: 2022/04/10 02:04:43 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include "gnl/get_next_line.h"
# include "ft_printf/bonus/ft_printf_bonus.h"

typedef long long	t_ll;

typedef struct s_stack
{
	struct s_stack	*prev;
	int				data;
	struct s_stack	*next;
}	t_stack;

typedef struct s_HEAD
{
	t_stack	*front;
	int		count;
	t_stack	*back;
}	t_HEAD;

typedef struct s_command
{
	char				*data;
	struct s_command	*next;
}	t_command;

typedef struct s_CHEAD
{
	t_command	*front;
	int			count;
	t_command	*back;
}	t_CHEAD;

typedef struct s_cnt
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_cnt;

void	exit_with_error(t_HEAD *a, t_HEAD *b, char *cmd);

void	push_front(t_HEAD *head, int data, t_HEAD *another);
void	push_back(t_HEAD *head, int data, t_HEAD *another);
void	pop_front(t_HEAD *head);
void	pop_back(t_HEAD *head);
void	free_stack(t_HEAD *a, t_HEAD *b);

int		arg_to_int(char *arg);
int		check_dup(t_HEAD *a, int data);
void	parse_arg(t_HEAD *a, t_HEAD *b, int argc, char *argv[]);

void	sa(t_HEAD *a);
void	sb(t_HEAD *b);
void	ss(t_HEAD *a, t_HEAD *b);
void	pa(t_HEAD *a, t_HEAD *b);
void	pb(t_HEAD *a, t_HEAD *b);
void	ra(t_HEAD *a);
void	rb(t_HEAD *b);
void	rr(t_HEAD *a, t_HEAD *b);
void	rra(t_HEAD *a);
void	rrb(t_HEAD *b);
void	rrr(t_HEAD *a, t_HEAD *b);

#endif