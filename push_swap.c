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
        {
            s->tail = current;
            current->next = NULL;
        }
        else
            current->next = malloc(sizeof(t_node));
        current = current->next;
        i++;
    }
}

t_stack *get_clean_data(int ac, char **av)
{
    t_stack *s;

    if (args_duplicated(av, ac))
        raise_error();
    s = malloc(sizeof(t_stack));
    get_nodes(ac, av, s);
    if (is_sorted(s))
        raise_error();
    return (s);

}

void    print_stack(char *action, t_stack *s)
{
    t_node *head;

    head = s->top;
    printf("----- %s -----\n", action);
    while (head)
    {
        printf("%d\n", head->content);
        head = head->next;
    }
}

int main(int ac, char **av)
{
    t_stack *a;
    t_stack *b;

    a = get_clean_data(ac, av);
    b = malloc(sizeof(t_stack));
    b->top =NULL;
    b->tail= NULL;
    print_stack("stack_a", a);
    sort_5n(a, b);
    print_stack("stack_a", a);
    print_stack("stack_b", b);
    if (a->top && a->tail)
        printf("a_top : %d a_tail: %d\n", a->top->content, a->tail->content);
}