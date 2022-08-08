#include "../push_swap.h"

void    insert_node(t_stack *s, t_node *new_node)
{
    t_node *old_node;

    old_node = s->top;
    if (s->top)
    {
        new_node->next = old_node;
        s->top = new_node;
    }
    else
    {
        new_node->next = NULL;
        s->top = new_node;
        s->tail = new_node;
    }
}

void    transfer_top(t_stack *from, t_stack *to)
{
    t_node *top_next;

    if (from->top)
    {
        top_next = from->top->next;
        insert_node(to, from->top);
        to->size++;
        if (top_next)
            from->top = top_next;
        else
        {
            from->tail = NULL;
            from->top = NULL;
        }
        from->size--;
    }
}

void    swap_ab(t_stack *a, t_stack *b, int muted)
{
    swap_a(a, TRUE);
    swap_b(b, TRUE);
    if (!muted)
        write(1, "ss\n", 3);
}

void    rotate_ab(t_stack *a, t_stack *b, int muted)
{
    rotate_a(a, TRUE);
    rotate_b(b, TRUE);
    if (!muted)
        write(1, "rr\n", 3);
}

void    rev_rotate_ab(t_stack *a, t_stack *b, int muted)
{
    rev_rotate_a(a, TRUE);
    rev_rotate_b(b, TRUE);
    if (!muted)
        write(1, "rrr\n", 4);
}