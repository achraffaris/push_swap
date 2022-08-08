#include "../push_swap.h"



int quick_push(t_stack *s)
{
    t_node *current;
    int i=0; 
    int j=0;
    current = s->top;
    while (current && !exists(s->ref_arr, current->id, s->ref_start, s->ref_end))
    {
        i++;
        current = current->next;
    }
    current = s->tail;
    while (current && !exists(s->ref_arr, current->id, s->ref_start, s->ref_end))
    {
        j++;
        current = current->previous;
    }
    if (i < j)
        return (RA);
    else
        return (RRA);
}
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
                if ((a->top && exists(a->ref_arr, b->top->id, a->ref_start, a->ref_middle)))
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

void    stack_b_migration(t_stack *a, t_stack *b)
{
    while (b->top || a->bs)
    {
        if (max_found_in(a, b, a->bs) == STACK_B)
        {
            if (max_found_in_bs(b))
            {
                while (b->bs)
                {
                    rev_rotate_b(b, FALSE);
                    b->bs--;
                    if (is_max(b, b->top->content))
                        break ;
                }
            }
            if (is_max(b, b->top->content))
                push_a(a, b, FALSE);
            else
            {
                if (a->bs || b->top->content > a->tail->content)
                {
                    push_a(a, b, FALSE);
                    if (b->top->content < a->tail->content)
                    {
                        rotate_ab(a, b, FALSE);
                        b->bs++;
                        a->bs++;
                    }
                    else
                    {
                        rotate_a(a, FALSE);
                        a->bs++;
                    }
                }
                else if (b->top->content < a->tail->content)
                {
                    rotate_b(b, FALSE);
                    b->bs++;
                }
            }
        }
        else
        {
            while (a->bs)
            {
                rev_rotate_a(a, FALSE);
                a->bs--;
                if (is_max_bs(a, a->bs, a->top->content))
                    break ;
                else
                    push_b(a, b, FALSE);
            }
        }
    }
}

void    chunk_sort(t_stack *a, t_stack *b)
{
    stack_a_migration(a, b);
    stack_b_migration(a, b);
}