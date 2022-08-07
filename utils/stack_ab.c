#include "../push_swap.h"

void    insert_node(t_stack *s, t_node *new_node)
{
    t_node *old_node;

    old_node = s->top;
    if (s->top)
    {
        new_node->next = old_node;
        old_node->previous = NULL;
        s->top = new_node;
    }
    else
    {
        s->top = new_node;
        s->tail = new_node;
        new_node->next = NULL;
    }
}

void    transfer_top(t_stack *from, t_stack *to)
{
    t_node *new_top;

    new_top = from->top->next;
    if(from->top)
    {
        insert_node(to, from->top);
        to->stack_size++;
        from->stack_size--;
        if (new_top)
        {
            from->top = new_top;
            from->top->previous = NULL;
        }
        else
        {
            from->tail = NULL;
            from->top = NULL;
        }
        if (from->size == 1)
            from->tail = from->top;
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