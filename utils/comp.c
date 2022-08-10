#include "../push_swap.h"

int is_max(t_node *start, t_node *node)
{
    t_node *current;

    current = start;
    while (current)
    {
        if (current->content > node->content)
            return (FALSE);
        current = current->next;   
    }
    return (TRUE);
}

int is_min(t_node *start, t_node *node)
{
    t_node *current;

    current = start;
    while (current)
    {
        if (current->content < node->content)
            return (FALSE);
        current = current->next;   
    }
    return (TRUE);
}