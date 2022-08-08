#include "../push_swap.h"

t_node *get_node_previous(t_stack *s, t_node *node)
{
    t_node *current;
    t_node *previous;

    current = s->top;
    previous = NULL;
    while (current)
    {
        if (current->id == node->id)
            break ;
        previous = current;
        current = current->next;
    }
    return (previous);
}