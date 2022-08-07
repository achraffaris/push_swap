#include "../push_swap.h"

void    swap_a(t_stack *s, int muted)
{
    t_node *a;
    t_node *b;

    if (s->top && s->top->next)
    {
        a = s->top;
        b = a->next;

        b->previous = NULL;
        a->previous = b;
        a->next = b->next;
        b->next = a;
        s->top = b;
        if (!muted)
            write(1, "sa\n", 3);
    }
}

void    push_a(t_stack *a, t_stack *b, int muted)
{
    if (b->top)
    {
        transfer_top(b, a);
        if (!muted)
            write(1, "pa\n", 3);
    }
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
        if (old_tail)
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

    if (s->tail && s->top)
    {
        old_top = s->top;
        tail_previous = s->tail->previous;
        s->top = s->tail;
        s->top->next = old_top;
        s->top->previous = NULL;
        s->tail = tail_previous;
        if (s->tail)
            s->tail->next = NULL;
        if (!muted)
            write(1, "rra\n", 4);
    }
}