#include "../push_swap.h"

void    sort_3n(t_stack *s)
{
    while (!is_sorted(s))
    {
        if (is_max(s->top, s->top))
        {
            if (is_min(s->top, s->top->next))
                rotate_a(s, FALSE);
            else
            {
                rotate_a(s, FALSE);
                swap_a(s, FALSE);
            }
        }
        else if (is_min(s->top, s->top))
        {
            rev_rotate_a(s, FALSE);
            swap_a(s, FALSE);
        }
        else
            swap_a(s, FALSE);
    }
}

void    sort_4n(t_stack *a, t_stack *b)
{
    t_node  *tail_previous;

    tail_previous = get_node_previous(a, a->tail);
    if (is_min(a->top, a->top->next))
        swap_a(a, FALSE);
    else if (is_min(a->top, a->tail))
        rev_rotate_a(a, FALSE);
    else if (is_min(a->top, tail_previous))
    {
        rev_rotate_a(a, FALSE);
        rev_rotate_a(a, FALSE);
    }
    push_b(a, b, FALSE);
    sort_3n(a);
    push_a(a, b, FALSE);
}

void    sort_5n(t_stack *a, t_stack *b)
{
    t_node  *tail_previous;

    tail_previous = get_node_previous(a, a->tail);
    if (is_min(a->top, a->top->next))
        swap_a(a, FALSE);
    else if (is_min(a->top, a->tail))
        rev_rotate_a(a, FALSE);
    else if (is_min(a->top, a->top->next->next))
    {
        rotate_a(a, FALSE);
        rotate_a(a, FALSE);
    }
    else if (is_min(a->top, tail_previous))
    {
        rev_rotate_a(a, FALSE);
        rev_rotate_a(a, FALSE);
    }
    push_b(a, b, FALSE);
    sort_4n(a, b);
    push_a(a, b, FALSE);
}

void    mini_sort(t_stack *a, t_stack *b, int ac)
{
    if (ac - 1 == 5)
        sort_5n(a, b);
    else if (ac - 1 == 4)
        sort_4n(a, b);
    else
        sort_3n(a);
}