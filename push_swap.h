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
    struct  node    *previous;
}   t_node;

typedef struct stack
{
    int     size;
    t_node  *top;
    t_node  *tail;
}   t_stack;

void    raise_error();
int     ft_atoi(const char *nptr);
int     is_number(char c);
int     is_sign(char c);
void    swap_a(t_stack *s);
void    ft_swap(int *a, int *b);
void    rotate_a(t_stack *s);
void    rev_rotate_a(t_stack *s);
void    push_a(t_stack *a, t_stack *b);
void    rotate_b(t_stack *s);
void    rev_rotate_b(t_stack *s);
void    push_b(t_stack *a, t_stack *b);
int     args_duplicated(char **av, int ac);
int     is_sorted(t_stack *s);
int     ft_strlen(char *str);
int     ft_strcmp(const char *s1, const char *s2);
void    sort_3n(t_stack *s);
int     is_min(t_stack *s, int n);
int     is_max(t_stack *s, int n);
void    swap_b(t_stack *s);
void    sort_5n(t_stack *a, t_stack *b);
void    sort_4n(t_stack *a, t_stack *b);
void    print_stack(char *action, t_stack *s);
void    mini_sort(t_stack *a, t_stack *b, int ac);


#endif