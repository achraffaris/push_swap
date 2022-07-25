#include "../push_swap.h"

void    swap_b(t_stack *s)
{
    t_node *a;
    t_node *b;

    a = s->top;
    b = a->next;
    ft_swap(&a->content, &b->content);
}

void    push_b(t_stack *a, t_stack *b)
{
    t_node *top_node;

    top_node = extract_node(b);
    if (top_node)
        insert_node(a, top_node);
}

void    rotate_b(t_stack *s)
{
    t_node *old_top;

    old_top = s->top;
    s->top = s->top->next;
    s->tail->next = old_top;
    old_top->next = NULL;
    s->tail = old_top;
}

void    rev_rotate_b(t_stack *s)
{
    t_node *prev_tail_node;
    t_node *current;

    current = s->top;
    while (current)
    {
        prev_tail_node = current;
        current = current->next;
        if (current->next == NULL)
            break ;
    }
    s->tail->next = s->top;
    s->top = s->tail;
    prev_tail_node->next = NULL;
    s->tail = prev_tail_node;
}