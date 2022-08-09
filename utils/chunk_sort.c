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

void    chunk_sort(t_stack *a, t_stack *b)
{
    stack_a_migration(a, b);
}