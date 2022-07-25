#include "checker.h"

void    get_nodes(int ac, char **av, t_stack *s)
{
    int     i;
    t_node  *current;
    t_node  *previous;

    i = 1;
    current = malloc(sizeof(t_node));
    previous = NULL;
    s->top = current;
    while (av[i])
    {
        current->previous = previous;
        current->content = ft_atoi(av[i]);
        if (i == ac - 1)
        {
            s->tail = current;
            current->next = NULL;
        }
        else
            current->next = malloc(sizeof(t_node));
        previous = current;
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
    /* check that later
    if (is_sorted(s))
        raise_error();
    */
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

void    exec_actions(t_stack *a, t_stack *b, char *action)
{
    if (ft_strcmp(action, SA) == 0)
        swap_a(a);
    else if (ft_strcmp(action, SB) == 0)
        swap_b(b);
    else if (ft_strcmp(action, RA) == 0)
        rotate_a(a);
    else if (ft_strcmp(action, RB) == 0)
        rotate_b(b);
    else if (ft_strcmp(action, RRA) == 0)
        rev_rotate_a(a);
    else if (ft_strcmp(action, RRB) == 0)
        rev_rotate_b(b);
    else
        raise_error();
}

void    actions_listener(t_stack *a, t_stack *b)
{
    char *buff;

    buff = get_next_line(0);
    while (buff)
    {
        exec_actions(a, b, buff);
        buff = get_next_line(0);
    }
    if (is_sorted(a) && (!b->top))
        write(1, "OK\n", 3);
    else
        write(1, "KO\n", 3);
}

int main(int ac, char **av)
{
    t_stack *a;
    t_stack *b;

    a = get_clean_data(ac, av);
    b = malloc(sizeof(t_stack));
    b->top =NULL;
    b->tail= NULL;
    actions_listener(a, b);
}