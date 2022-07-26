#include "../push_swap.h"

t_node  *get_tail_antecedent(t_stack *s)
{
    t_node *current;

    current = s->top;
    while (current)
    {
        if (current->next->next == NULL)
            return (current);
        current = current->next;
    }
    return (current);
}

void    sort_3n(t_stack *s)
{
    while (!is_sorted(s))
    {
        if (is_max(s, s->top->content))
        {
            if (is_min(s, s->top->next->content))
                rotate_a(s, FALSE);
            else
            {
                rotate_a(s, FALSE);
                swap_a(s, FALSE);
            }
        }
        else if (is_min(s, s->top->content))
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
    if (is_min(a, a->top->next->content))
        swap_a(a, FALSE);
    else if (is_min(a, a->tail->content))
        rev_rotate_a(a, FALSE);
    else if (is_min(a, a->tail->previous->content))
    {
        rev_rotate_a(a, FALSE);
        rev_rotate_a(a, FALSE);
    }
    push_a(a, b, FALSE);
    sort_3n(a);
    push_b(a, b, FALSE);
}

void    sort_5n(t_stack *a, t_stack *b)
{
    if (is_min(a, a->top->next->content))
        swap_a(a, FALSE);
    else if (is_min(a, a->tail->content))
        rev_rotate_a(a, FALSE);
    else if (is_min(a, a->top->next->next->content))
    {
        rotate_a(a, FALSE);
        rotate_a(a, FALSE);
    }
    else if (is_min(a, a->tail->previous->content))
    {
        rev_rotate_a(a, FALSE);
        rev_rotate_a(a, FALSE);
    }
    push_a(a, b, FALSE);
    sort_4n(a, b);
    push_b(a, b, FALSE);
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