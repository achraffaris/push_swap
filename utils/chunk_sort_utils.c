# include "../push_swap.h"

void    update_reference_indexes(t_stack *s, int lt, int gt)
{
    if (lt == s->reference->least_size)
    {
        s->reference->start -= s->offset;
        if (s->reference->start < 0)
            s->reference->start = 0;
        s->reference->least_size = (s->reference->middle + 1) - s->reference->start;
    }
    else if (gt == s->reference->greatest_size)
    {
        s->reference->end += s->offset; 
        if (s->reference->end >= s->reference->size)
            s->reference->end = s->reference->size - 1;
        s->reference->greatest_size = s->reference->end - s->reference->middle;
    }
}

t_node    *find_max(t_node *start, int *pos)
{
    t_node *current;

    current = start;
    while (current)
    {
        if (is_max(start, current))
            return (current);
        current = current->next;
        *pos += 1;
    }
    return (current);
}

int max_location(t_stack *a, t_stack *b)
{
    int pos;

    pos = 0;
    t_node *a_bottom_max;
    t_node *b_max;

    a_bottom_max = find_max(a->bottom_space->start, &pos);
    b_max = find_max(b->top, &pos);

    if (a_bottom_max && a_bottom_max->content > b_max->content)
        return (BOTTOM_STACK_A);
    else
    {
        if (b->bottom_space->size && pos >= (b->size - b->bottom_space->size))
            return (BOTTOM_STACK_B);
        else
            return (STACK_B);
    }
}