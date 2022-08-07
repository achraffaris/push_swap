#include "../push_swap.h"

void    stack_a_migration(t_stack *a, t_stack *b)
{
    int i;
    while (a->top)
    {
        i = 0;
        // overflow estimations
        a->transfers = (a->ref_end - a->ref_start + 1) - b->stack_size;
        while (i < a->transfers)
        {
            if (exists(a->ref_arr, a->top->id, a->ref_start, a->ref_end))
            {
                push_b(a, b, FALSE);
                if ((a->top && exists(a->ref_arr, b->top->id, a->ref_start, a->ref_middle)) || b->top->content < b->tail->content)
                    rotate_b(b, FALSE);
                if (b->top && b->top->next && b->top->content < b->top->next->content)
                    swap_b(b, FALSE);
                i++;
            }
            else
                rotate_a(a, FALSE);
        }
        a->ref_end += a->offset;
        if (a->ref_end >= a->ref_size)
            a->ref_end = a->ref_size - 1;
        a->ref_start -= a->offset;
        if (a->ref_start < 0)
           a->ref_start = 0;
    }
}

void    chunk_sort(t_stack *a, t_stack *b)
{
    stack_a_migration(a, b);
}