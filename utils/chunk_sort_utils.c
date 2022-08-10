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
    if (gt == s->reference->greatest_size)
    {
        s->reference->end += s->offset; 
        if (s->reference->end >= s->reference->size)
            s->reference->end = s->reference->size - 1;
        s->reference->greatest_size = s->reference->end - s->reference->middle;
    }
}

t_node    *find_max(t_node *start)
{
    t_node *current;

    current = start;
    while (current)
    {
        if (is_max(start, current))
            return (current);
        current = current->next;
    }
    return (current);
}

int max_location(t_stack *a, t_stack *b)
{
    t_node *a_bottom_max;
    t_node *b_bottom_max;
    t_node *b_max;
    
    b_bottom_max = find_max(b->bottom_space->start);
    a_bottom_max = find_max(a->bottom_space->start);
    b_max = find_max(b->top);
    /* 
    ** if max_found in bottom of stack_b;
    ** then, b_max == b_bottom_max;
    ** hence, bottom_stack_b should be returned since the max found in the bottom of the same stack;
    ** otherwise, stack_b should be returned since the max of stack-b bottom is different from max stack_b;
    ** in a nutshell, b_bottom_max will always hold the max regardless of it location.
    */
    if (!b->top)
        return (BOTTOM_STACK_A);
    if (a_bottom_max && (a_bottom_max->content > b_max->content))
        return (BOTTOM_STACK_A);
    else
    {
        if (b->bottom_space->size && b_max == b_bottom_max)
            return (BOTTOM_STACK_B);
        else
            return (STACK_B);
    }
}