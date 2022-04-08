#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>

# include <unistd.h>
# include <stdlib.h>
# include "ft_printf/bonus/ft_printf_bonus.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef long long t_ll;

typedef struct	s_stack
{
	struct s_stack	*prev;
	int				data;
	struct s_stack	*next;
}	t_stack;

typedef struct  s_HEAD
{
	t_stack	*front;
	int		count;
	t_stack *back;
}	t_HEAD;

typedef struct  s_command
{
	char				*data;
    struct s_command	*next;
} t_command;

typedef struct s_CHEAD
{
	t_command *front;
	int count;
	t_command *back;
} t_CHEAD;

typedef struct	s_cnt
{
	int sa;
	int sb;
	int ss;
	int pa;
	int pb;
	int ra;
	int rb;
	int rr;
	int rra;
	int rrb;
	int rrr;
}	t_cnt;

void print_stack(t_HEAD head);
void exit_with_error(t_HEAD *A, t_HEAD *B, t_CHEAD *cmd);

// stack_utils
// cmd도 같이 free 시켜주는 부분 필요.
// parsing 시에는 cmd가 아직 생성되어 있지 않으므로 null을 넣어 처리하지 않게 한다 !
void	push_front(t_HEAD *head, int data, t_HEAD *another, t_CHEAD *cmd);
void	push_back(t_HEAD *head, int data, t_HEAD *another, t_CHEAD *cmd);
void	pop_front(t_HEAD *head);
void	pop_back(t_HEAD *head);
void	free_stack(t_HEAD *A, t_HEAD *B);

// parse_arg
int		arg_to_int(char *arg);
int		check_dup(t_HEAD *A, int data);
void	parse_arg(t_HEAD *A, t_HEAD *B, int argc, char *argv[]);

// sort_utils
int		getpivotA(int n, t_HEAD *head, int *pv1, int *pv2);
int		getpivotB(int n, t_HEAD *head, int *pv1, int *pv2);
void	sort_pieceA(int n, t_HEAD *A, t_HEAD *B, t_CHEAD *cmd);
void	sort_pieceB(int n, t_HEAD *A, t_HEAD *B, t_CHEAD *cmd);
void	init_cnt(t_cnt *cnt);

// sort_stacks
void	atob(int n, t_HEAD *A, t_HEAD *B, t_CHEAD *cmd);
void	btoa(int n, t_HEAD *A, t_HEAD *B, t_CHEAD *cmd);
// return 값을 맞춰주기
t_cnt	div_atob(int n, t_HEAD *A, t_HEAD *B, t_CHEAD *cmd);
t_cnt	div_btoa(int n, t_HEAD *A, t_HEAD *B, t_CHEAD *cmd);

// stack_commands
void	sa(t_HEAD *A, t_HEAD *B, t_CHEAD *cmd);
void	sb(t_HEAD *A, t_HEAD *B, t_CHEAD *cmd);
void	pa(t_HEAD *A, t_HEAD *B, t_CHEAD *cmd);
void	pb(t_HEAD *A, t_HEAD *B, t_CHEAD *cmd);
void	ra(t_HEAD *A, t_HEAD *B, t_CHEAD *cmd);
void	rb(t_HEAD *A, t_HEAD *B, t_CHEAD *cmd);
void	rra(t_HEAD *A, t_HEAD *B, t_CHEAD *cmd);
void	rrb(t_HEAD *A, t_HEAD *B, t_CHEAD *cmd);
void	rrr(t_HEAD *A, t_HEAD *B, t_CHEAD *cmd);

// cmd_utils
int		check_merge(char *s, t_CHEAD *cmd);
void	cmd_push(char *s, t_HEAD *A, t_HEAD *B, t_CHEAD *cmd);
void	free_cmd(t_CHEAD *cmd);
void	print_cmd(t_CHEAD cmd);

#endif