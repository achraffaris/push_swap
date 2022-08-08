# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define INT_MAX 2147483647
# define INT_MIN 2147483648
# define FALSE 0
# define TRUE 1
# define STACK_A 'a'
# define STACK_B 'b'
# define RA 2
# define RRA 3
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

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
    int             n;
    int             stack_size;
    int             offset;
    int             *ref_arr;
    int             transfers;
    int             ref_size;
    int             ref_middle;
    int             ref_start;
    int             ref_end;
    int             bs;
}   t_stack;

void                raise_error();
int                 ft_atoi(const char *nptr);
int                 is_number(char c);
int                 is_sign(char c);
void                swap_a(t_stack *s, int muted);
void                ft_swap(int *a, int *b);
void                rotate_a(t_stack *s, int muted);
void                rev_rotate_a(t_stack *s, int muted);
void                push_a(t_stack *a, t_stack *b, int muted);
void                rotate_b(t_stack *s, int muted);
void                rev_rotate_b(t_stack *s, int muted);
void                push_b(t_stack *a, t_stack *b, int muted);
int                 args_duplicated(char **av, int ac);
int                 is_sorted(t_stack *s);
int                 ft_strlen(char *str);
int                 ft_strcmp(char *s1, char *s2);
void                sort_3n(t_stack *s);
int                 is_min(t_stack *s, int n);
int                 is_max(t_stack *s, int n);
void                swap_b(t_stack *s, int muted);
void                sort_5n(t_stack *a, t_stack *b);
void                sort_4n(t_stack *a, t_stack *b);
void                mini_sort(t_stack *a, t_stack *b, int ac);
void                insert_node(t_stack *s, t_node *new_node);
void                transfer_top(t_stack *from, t_stack *to);
void                swap_ab(t_stack *a, t_stack *b, int muted);
void                rotate_ab(t_stack *a, t_stack *b, int muted);
void                rev_rotate_ab(t_stack *a, t_stack *b, int muted);
t_stack             *stack_a_init(int ac, char **av);
t_stack             *empty_stack_init();
int                 exists(int *ref_arr, int node_id, int start, int end);
void                chunk_sort(t_stack *a, t_stack *b);
char                max_found_in(t_stack *a, t_stack *b, int bs);
int                 is_max_bs(t_stack *s, int bs, int nb);
int                 max_found_in_bs(t_stack *s);
#endif