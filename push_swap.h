#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define INT_MAX 2147483647
# define INT_MIN 2147483648
# define TAIL 0
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct node
{
    int             content;
    struct  node    *next;
}   t_node;

typedef struct stack
{
    int     size;
    t_node  *top;
    t_node  *tail;
}   t_stack;

void    raise_error();
int     ft_atoi(const char *nptr);
int is_number(char c);
int is_sign(char c);






#endif