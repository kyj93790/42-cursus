#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct  s_stack {
    struct s_stack	*prev;
    int				data;
    struct s_stack	*next;
}   t_stack;

typedef struct s_HEAD {
    t_stack	*front;
    int		count;
    t_stack *back;
}   t_HEAD;

typedef struct s_command {
	char				cmd[5];
    struct s_command	*next;
} t_command;

#endif