#include "push_swap.h"

// ./ps 2 5 0 1 

// each node has a unique content, and a pointer to his following node.
void    get_nodes(int ac, char **av, t_stack *s)
{
    int     i;
    t_node  *current;
    i = 1;
    current = malloc(sizeof(t_node));
    s->top = current;
    while (av[i])
    {
        current->content = ft_atoi(av[i]);
        if (i == ac - 1)
            current->next = NULL;
        else
            current->next = malloc(sizeof(t_node));
        current = current->next;
        i++;
    }
    s->tail = current;
}

t_stack *get_clean_data(int ac, char **av)
{
    t_stack *s;

    s = malloc(sizeof(t_stack));
    get_nodes(ac, av, s);
    return (s);

}

int main(int ac, char **av)
{
    t_stack *s;

    s = get_clean_data(ac, av);
    t_node *head;

    head = s->top;
    while (head)
    {
        printf("content = %d\n", head->content);
        head = head->next;
    }    
}