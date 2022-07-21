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
                rotate_a(s);
            else
            {
                rotate_a(s);
                swap_a(s);
            }
        }
        else if (is_min(s, s->top->content))
        {
            rev_rotate_a(s);
            swap_a(s);
        }
        else
            swap_a(s);
    }
}

void    sort_5n(t_stack *a, t_stack *b)
{
    t_node *tail_antecedent;
    int n;

    n = a->size - 3;
    while (n)
    {
        tail_antecedent = get_tail_antecedent(a);
        if (is_min(a, a->top->next->content))
            swap_a(a);
        else if (is_min(a, a->tail->content))
            rev_rotate_a(a);
        else if (is_min(a, tail_antecedent->content))
        {
            rev_rotate_a(a);
            rev_rotate_a(a);
        }
        else
        {
            rotate_a(a);
            swap_a(a);
        }
        push_b(a, b);
    }
    sort_3n(a);
    if (is_sorted(b))
        swap_b(b);
    push_b(a, b);
    push_b(a, b);
}