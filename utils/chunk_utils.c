#include "../push_swap.h"

int exists(int *ref_arr, int node_id, int start, int end)
{
    int i;

    i = start;
    while (i <= end)
    {
        if (ref_arr[i] == node_id)
            return (TRUE);
        i++;
    }
    return (FALSE);
}

char max_found_in(t_stack *a, t_stack *b, int bs)
{
    t_node *current;
    t_node *max_b;
    t_node *max_a;

    current = b->top;
    max_b = current;
    while (current)
    {
        if (max_b && current->next && max_b->content < current->next->content)
            max_b = current->next;
        current = current->next;
    }
    if (!bs)
        return (STACK_B);
    current = a->tail;
    max_a = current;
    while (bs && max_a && current->previous)
    {
        if (max_a && current && current->previous && max_a->content < current->previous->content && bs - 1 > 0)
        {
            max_a = current->previous;
            bs--;
        }
        current = current->previous;
        bs--;
    }
    if (!max_b || (max_a && max_a->content > max_b->content))
        return (STACK_A);
    else
        return (STACK_B);
}

int is_max_bs(t_stack *s, int bs, int nb)
{
    t_node *current;

    current = s->tail;
    while (bs && current)
    {
        if (current && nb < current->content )
            return (FALSE);
        current = current->previous;
        bs--;
    }
    return (TRUE);
}

int max_found_in_bs(t_stack *s)
{
    int bs;
    t_node *current;

    current = s->tail;
    if (!s->bs)
        return (FALSE);
    bs = s->bs;
    while (bs)
    {
        if (is_max(s, current->content))
            return (TRUE);
        current = current->previous;
        bs--;
    }
    return (FALSE);
}

