#include "../push_swap.h"

void    sort_stack_ref(t_stack *s)
{
    int i;

    i = 0;
    t_node *min;

    printf("arr[index][node_id]\n");
    while (s->top)
    {
        if (is_min(s, s->top->content))
        {
            min = extract_node(s);
            s->arr_ref[i] = min->id;
            printf("     [%d]     [%d]\n", i, s->arr_ref[i]);
            free(min);
            i++;
        }
        else
            rotate_a(s, TRUE);
    }
}