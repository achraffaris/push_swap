#include "../push_swap.h"

void    sort_stack_ref(t_stack *s)
{
    int i;

    i = 0;
    t_stack *trash;

    trash = empty_stack_init();
    while (s->top)
    {
        if (is_min(s, s->top->content))
        {
            s->ref_arr[i] = s->top->id;
            transfer_top(s, trash);
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
    ac--;
    int j = ac;
    while (av[i])
    {
        current->id = ac;
        current->content = ft_atoi(av[i]);
        if (i == 1)
        {
            s->top = current;
            s->top->previous = NULL;
        }
        else
            current->previous = previous;
        if (i == j)
        {
            current->next = NULL;
            s->tail = current;
        }
        else
            current->next = malloc(sizeof(t_node));   
        previous = current;
        current = current->next;
        i++;
        ac--;
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
        exit(EXIT_FAILURE);
    if (s->stack_size <= 10)
        s->n = 5;
    else if (s->stack_size > 10 && s->stack_size <= 150)
        s->n = 8;
    else
        s->n = 11;
    s->offset = s->stack_size / s->n;
    s->ref_middle = (s->ref_size / 2) - 1;
    s->ref_start = s->ref_middle - s->offset;
    s->ref_end = s->ref_middle + s->offset;
    s->bs = 0;
    return (s);
}

t_stack *empty_stack_init()
{
    t_stack *s;

    s = malloc(sizeof(t_stack));
    if (!s)
        raise_error();
    s->tail = NULL;
    s->top = NULL;
    s->stack_size = 0;
    s->bs = 0;
    return (s);
}