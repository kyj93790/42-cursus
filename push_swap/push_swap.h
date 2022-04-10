/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejikim <yejikim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 02:03:35 by yejin             #+#    #+#             */
/*   Updated: 2022/04/10 13:27:00 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
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

void	exit_with_error(t_HEAD *a, t_HEAD *b, t_CHEAD *cmd);

void	push_front(t_HEAD *head, int data, t_HEAD *another, t_CHEAD *cmd);
void	push_back(t_HEAD *head, int data, t_HEAD *another, t_CHEAD *cmd);
void	pop_front(t_HEAD *head);
void	pop_back(t_HEAD *head);
void	free_stack(t_HEAD *a, t_HEAD *b);

t_ll	arg_to_int(t_HEAD *a, t_HEAD *b, char *arg);
int		check_dup(t_HEAD *a, int data);
void	parse_arg(t_HEAD *a, t_HEAD *b, int argc, char *argv[]);

int		getpivot_a(int n, t_HEAD *head, int *pv1, int *pv2);
int		getpivot_b(int n, t_HEAD *head, int *pv1, int *pv2);
void	sort_piece_a(int n, t_HEAD *a, t_HEAD *b, t_CHEAD *cmd);
void	sort_piece_b(int n, t_HEAD *a, t_HEAD *b, t_CHEAD *cmd);
void	init_cnt(t_cnt *cnt);

void	atob(int n, t_HEAD *a, t_HEAD *b, t_CHEAD *cmd);
void	btoa(int n, t_HEAD *a, t_HEAD *b, t_CHEAD *cmd);
t_cnt	div_atob(int n, t_HEAD *a, t_HEAD *b, t_CHEAD *cmd);
t_cnt	div_btoa(int n, t_HEAD *a, t_HEAD *b, t_CHEAD *cmd);

void	sa(t_HEAD *a, t_HEAD *b, t_CHEAD *cmd, t_cnt *cnt);
void	sb(t_HEAD *a, t_HEAD *b, t_CHEAD *cmd, t_cnt *cnt);
void	pa(t_HEAD *a, t_HEAD *b, t_CHEAD *cmd, t_cnt *cnt);
void	pb(t_HEAD *a, t_HEAD *b, t_CHEAD *cmd, t_cnt *cnt);
void	ra(t_HEAD *a, t_HEAD *b, t_CHEAD *cmd, t_cnt *cnt);
void	rb(t_HEAD *a, t_HEAD *b, t_CHEAD *cmd, t_cnt *cnt);
void	rra(t_HEAD *a, t_HEAD *b, t_CHEAD *cmd, t_cnt *cnt);
void	rrb(t_HEAD *a, t_HEAD *b, t_CHEAD *cmd, t_cnt *cnt);
void	rrr(t_HEAD *a, t_HEAD *b, t_CHEAD *cmd, t_cnt *cnt);

int		check_merge(char *s, t_CHEAD *cmd);
void	cmd_push(char *s, t_HEAD *a, t_HEAD *b, t_CHEAD *cmd);
void	free_cmd(t_CHEAD *cmd);
void	print_cmd(t_CHEAD cmd);

#endif