#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define INT_MAX 2147483647
# define INT_MIN 2147483648
# define FALSE 0
# define TRUE 1

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct node
{
    int             content;
    int             id;
    struct  node    *next;
    struct  node    *previous;
}   t_node;

typedef struct stack
{
    int             size;
    t_node          *top;
    t_node          *tail;
    int             *arr_ref;
    int             arr_size;
    int             stack_size;
}   t_stack;

void    raise_error();
int     ft_atoi(const char *nptr);
int     is_number(char c);
int     is_sign(char c);
void    swap_a(t_stack *s, int muted);
void    ft_swap(int *a, int *b);
void    rotate_a(t_stack *s, int muted);
void    rev_rotate_a(t_stack *s, int muted);
void    push_a(t_stack *a, t_stack *b, int muted);
void    rotate_b(t_stack *s, int muted);
void    rev_rotate_b(t_stack *s, int muted);
void    push_b(t_stack *a, t_stack *b, int muted);
int     args_duplicated(char **av, int ac);
int     is_sorted(t_stack *s);
int     ft_strlen(char *str);
int     ft_strcmp(char *s1, char *s2);
void    sort_3n(t_stack *s);
int     is_min(t_stack *s, int n);
int     is_max(t_stack *s, int n);
void    swap_b(t_stack *s, int muted);
void    sort_5n(t_stack *a, t_stack *b);
void    sort_4n(t_stack *a, t_stack *b);
void    print_stack(char *action, t_stack *s);
void    mini_sort(t_stack *a, t_stack *b, int ac);
void    insert_node(t_stack *s, t_node *new_node);
t_node  *extract_node(t_stack *s);
void    swap_ab(t_stack *a, t_stack *b, int muted);
void    rotate_ab(t_stack *a, t_stack *b, int muted);
void    rev_rotate_ab(t_stack *a, t_stack *b, int muted);
void    sort_stack_ref(t_stack *s);

#endif