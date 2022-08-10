#include "../push_swap.h"

t_stack *empty_stack_creation()
{
    t_stack *s;

    s = malloc(sizeof(t_stack));
    if (!s)
        raise_error();
    s->tail = NULL;
    s->top = NULL;
    s->bottom_space = malloc(sizeof(s->bottom_space));
    if (!s->bottom_space)
        raise_error();
    return (s);
}

void    sort_reference_array(t_stack *copy, t_stack *s)
{
    int i;

    i = 0;
    t_stack *tmp;
    tmp = empty_stack_creation();
    while (copy->top)
    {
        if (is_min(copy->top, copy->top))
        {
            s->reference->array[i] = copy->top->id;
            transfer_top(copy, tmp);
            i++;
        }
        else
            rotate_a(copy, TRUE);
    }
}

void    nodes_creation(int ac, char **av, t_stack *s)
{
    int     i;
    int     j;
    t_node  *current;

    i = 1;
    j = ac - 1;
    current = malloc(sizeof(t_node));
    if (!current)
        raise_error();
    s->top = current;
    while (av[i])
    {
        current->id = ac - 1;
        current->content = ft_atoi(av[i]);
        if (i == 1)
            s->top = current;
        if (i == j)
        {
            current->next = NULL;
            s->tail = current;
        }
        else
            current->next = malloc(sizeof(t_node));   
        current = current->next;
        i++;
        ac--;
    }
}

void    reference_creation(int ac, char **av, t_stack *s)
{
    t_stack *copy;

    copy = empty_stack_creation();
    nodes_creation(ac, av, copy);
    s->reference = malloc(sizeof(s->reference));
    if (!s->reference)
        raise_error();
    s->reference->size = ac - 1;
    s->reference->array = malloc(sizeof(t_stack) * s->reference->size);
    if (!s->reference->array)
        raise_error();
    s->reference->middle = s->reference->size / 2;
    s->reference->start = s->reference->middle - s->offset;
    if (s->reference->start < 0)
        s->reference->start = 0;
    s->reference->end = s->reference->middle + s->offset;
    if (s->reference->end >= s->reference->size)
        s->reference->end = s->reference->size - 1;
    s->reference->least_size = (s->reference->middle + 1) - s->reference->start;
    s->reference->greatest_size = s->reference->end - s->reference->middle;
    copy->size = s->size;
    sort_reference_array(copy, s);
}

t_stack *stack_a_creation(int ac, char **av)
{
    t_stack *s;
    
    s = malloc(sizeof(t_stack));
    if (args_duplicated(av, ac) || !s)
        raise_error();
    s->size = ac - 1;
    if (s->size <= 10)
        s->n = 5;
    else if (s->size <= 150)
        s->n = 8;
    else
        s->n = 18;
    s->offset = s->size / s->n;
    s->bottom_space = malloc(sizeof(s->bottom_space));
    if (!s->bottom_space)
        raise_error();
    s->bottom_space->start = NULL;
    nodes_creation(ac, av, s);
    reference_creation(ac, av, s);
    return (s);
}

