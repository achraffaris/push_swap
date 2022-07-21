#include "../push_swap.h"

int args_duplicated(char **av, int ac)
{
    int i;
    int j;

    i = 1;
    j = 0;
    while (i < ac)
    {
        j = i + 1;
        while (j < ac)
        {
            if (ft_strcmp(av[i], av[j]) == 0)
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

int is_sorted(t_stack *s)
{
    t_node *current;

    current = s->top;
    while (current)
    {
        if (current->next && current->content > current->next->content)
            return (0);
        current = current->next;
    }
    return (1);
}