#include "../push_swap.h"

int is_max(t_stack *s, int n)
{
    t_node *current;

    current = s->top;
    while (current)
    {
        if (current->content > n)
            return (0);
        current = current->next;   
    }
    return (1);
}

int is_min(t_stack *s, int n)
{
    t_node *current;

    current = s->top;
    while (current)
    {
        if (current->content < n)
            return (0);
        current = current->next;   
    }
    return (1);
}