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
}   t_node;

typedef struct reference
{
    int             *array;
    int             size;
    int             start;
    int             end;
    int             middle;
}   t_reference;

typedef struct bottom_space
{
    int             size;
    t_node          *start;
}   t_bottom_space;

typedef struct stack
{
    
    t_node          *top;
    t_node          *tail;
    int             n;
    int             size;
    int             offset;
    t_reference     *reference;
    t_bottom_space  *bottom_space;
    t_node          *nodes;
}   t_stack;

void                raise_error();
int                 ft_atoi(const char *nptr);
int                 is_number(char c);
int                 is_sign(char c);
void                swap_a(t_stack *s, int muted);
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
// int                 exists(int *ref_arr, int node_id, int start, int end);


t_node              *get_node_previous(t_stack *s, t_node *node);
t_stack             *empty_stack_creation();
void                sort_reference_array(t_stack *copy, t_stack *s);
void                nodes_creation(int ac, char **av, t_stack *s);
void                reference_creation(int ac, char **av, t_stack *s);
t_stack             *stack_a_creation(int ac, char **av);
#endif