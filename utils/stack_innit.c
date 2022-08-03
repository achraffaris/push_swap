#include "../push_swap.h"

void    sort_stack_ref(t_stack *s)
{
    int i;

    i = 0;
    t_node *min;

    while (s->top)
    {
        if (is_min(s, s->top->content))
        {
            min = extract_node(s);
            s->ref_arr[i] = min->id;
            free(min);
            i++;
        }
        else
            rotate_a(s, TRUE);
    }
}

void    create_nodes(int ac, char **av, t_stack *s)
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
        current->id = i;
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

int *get_stack_ref(int ac, char **av)
{
    t_stack *s;
    
    s = malloc(sizeof(t_stack));
    if (!s)
        raise_error();
    create_nodes(ac, av, s);
    s->ref_arr = malloc(sizeof(int) * (ac - 1));
    if (!s->ref_arr)
        raise_error();
    sort_stack_ref(s);
    return (s->ref_arr);
}

t_stack *stack_a_init(int ac, char **av)
{
    t_stack *s;
    
    s = malloc(sizeof(t_stack));
    if (args_duplicated(av, ac) || !s)
        raise_error();
    create_nodes(ac, av, s);
    s->stack_size = ac - 1;
    s->ref_size = s->stack_size;
    s->ref_arr = get_stack_ref(ac, av);
    if (is_sorted(s))
        raise_error();
    if (s->stack_size <= 10)
        s->n = 5;
    else if (s->stack_size > 10 && s->stack_size <= 150)
        s->n = 8;
    else
        s->n = 18;
    s->offset = s->stack_size / s->n;
    s->ref_middle = (s->ref_size / 2) - 1;
    s->ref_start = s->ref_middle - s->offset;
    s->ref_end = s->ref_middle + s->offset;
    return (s);
}

t_stack *stack_b_init()
{
    t_stack *s;

    s = malloc(sizeof(t_stack));
    if (!s)
        raise_error();
    s->tail = NULL;
    s->top = NULL;
    s->stack_size = 0;
    return (s);
}