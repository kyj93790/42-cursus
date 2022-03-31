#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// # include <stdio.h>

# include <unistd.h>
# include <stdlib.h>
// # include "ft_printf/bonus/ft_printf_bonus.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef long long t_ll;

typedef struct  s_stack
{
    struct s_stack	*prev;
    int				data;
    struct s_stack	*next;
}   t_stack;

typedef struct  s_HEAD
{
    t_stack	*front;
    int		count;
    t_stack *back;
}   t_HEAD;

typedef struct  s_command
{
	char				cmd[5];
    struct s_command	*next;
} t_command;

// stack_utils
void    push_front(t_HEAD *head, int data, t_HEAD *another);
void    push_back(t_HEAD *head, int data, t_HEAD *another);
void    pop_front(t_HEAD *head);
void    pop_back(t_HEAD *head);
void    free_stack(t_HEAD *stack1, t_HEAD *stack2);

// parse_arg
int     arg_to_int(char *arg);
int     check_dup(t_HEAD *A, int data);
void    parse_arg(t_HEAD *A, t_HEAD *B, int argc, char *argv[]);

#endif