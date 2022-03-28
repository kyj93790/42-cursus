#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct  s_stack {
    int data;
    s_stack *next;
}   t_stack;

typedef struct s_HEAD {
    s_stack *front;
    int count;
    s_stack *back;
}   t_HEAD;

#endif