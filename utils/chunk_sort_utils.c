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