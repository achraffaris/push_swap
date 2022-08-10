#include "../push_swap.h"

int node_id_found(t_stack *s, int node_id, int *index)
{
    int i;
    int end;

    i = s->reference->start;
    end = s->reference->end;
    while (i <= end)
    {
        if (s->reference->array[i] == node_id)
        {
            *index = i;
            return (TRUE);
        }
        i++;
    }
    return (FALSE);
}

void    add_to_bottom(t_stack *s, int stack)
{
    if (stack == STACK_B)
        rotate_b(s, FALSE);
    else
        rotate_a(s, FALSE);
    if (!s->bottom_space->start)
        s->bottom_space->start = s->tail;
    s->bottom_space->size++;
}

void    move_bottom_to_top(t_stack *s, int stack)
{
    if (stack == STACK_B)
        rev_rotate_b(s, FALSE);
    else
        rev_rotate_a(s, FALSE);
    s->bottom_space->size--;
    if (s->bottom_space->size == 0)
        s->bottom_space->start = NULL;
}

void    stack_b_migration(t_stack *a, t_stack *b)
{
    int max_loc;

    while (b->top || a->bottom_space->start)
    {
        max_loc = max_location(a, b);
        if (max_loc == STACK_B)
        {
            if (is_max(b->top, b->top))
                push_a(a, b, FALSE);
            else if ((a->size && a->bottom_space->size == 0) || (a->tail && b->top->content > a->tail->content))
            {
                push_a(a, b, FALSE);
                add_to_bottom(a, STACK_A);
            }
            else
                add_to_bottom(b, STACK_B);
        }
        else if (max_loc == BOTTOM_STACK_B)
            max_move_up(a, b, BOTTOM_STACK_B);
        else
            max_move_up(a, b, BOTTOM_STACK_A);
    }
    
}

void    stack_a_migration(t_stack *a, t_stack *b)
{
    int lt;
    int gt;
    int index;

    lt = 0;
    gt = 0;
    while (a->top)
    {
        if (lt == a->reference->least_size || gt == a->reference->greatest_size)
            update_reference_indexes(a, lt, gt);
        if (node_id_found(a, a->top->id, &index))
        {
            if (index <= a->reference->middle)
            {
                push_b(a, b, FALSE);
                rotate_b(b, FALSE);
                lt++;
            }
            else
            {
                push_b(a, b, FALSE);
                gt++;
            }
        }
        else
            rotate_a(a, FALSE);
    }
}
