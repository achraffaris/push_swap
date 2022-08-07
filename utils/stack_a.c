#include "../push_swap.h"

void    swap_a(t_stack *s, int muted)
{
    t_node *a;
    t_node *b;

    // a point to the head of the linked nodes.
    // b point to the next node of a, so b is the antecedant of a.
    if (s->top && s->top->next)
    {
        a = s->top;
        b = a->next;
    
        ft_swap(&a->content, &b->content);
        if (!muted)
            write(1, "sa\n", 3);
    }
}

void    push_a(t_stack *a, t_stack *b, int muted)
{
    t_node *top_node;

    top_node = extract_node(a);
    if (top_node)
    {
        insert_node(b, top_node);
        b->stack_size++;
        a->stack_size--;
    }
    if (!muted)
        write(1, "pa\n", 3);
}

void    rotate_a(t_stack *s, int muted)
{
    t_node *old_top;
    t_node *old_tail;

    if (s->top && s->top->next)
    {
        old_top = s->top;
        old_tail = s->tail;
        s->top = old_top->next;
        s->top->previous = NULL;
        old_top->next = NULL;
        old_tail->next = old_top;
        old_top->previous = old_tail;
        s->tail = old_top;
        if (!muted)
            write(1, "ra\n", 3);
    }
}

void    rev_rotate_a(t_stack *s, int muted)
{
    t_node *old_top;
    t_node *tail_previous;

    if (s->top && s->top->next)
    {
        old_top = s->top;
        tail_previous = s->tail->previous;
        s->top = s->tail;
        s->top->next = old_top;
        s->top->previous = NULL;
        s->tail = tail_previous;
        s->tail->next = NULL;
        if (!muted)
            write(1, "rra\n", 4);
    }
}