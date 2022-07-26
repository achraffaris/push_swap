#include "push_swap.h"

// ./ps 2 5 0 1 

// need to be optimized
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

t_stack *stack_init(int ac, char **av)
{
    t_stack *s;
    if (args_duplicated(av, ac))
        raise_error();
    s = malloc(sizeof(t_stack));
    create_nodes(ac, av, s);
    s->stack_size = ac - 1;
    s->arr_size = s->stack_size;
    s->arr_ref = malloc(sizeof(int) * s->arr_size);
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
    printf("    [id]    [content]\n");
    while (head)
    {
        printf("     [%d]      [%d]\n", head->id, head->content);
        head = head->next;
    }
}

int main(int ac, char **av)
{
    t_stack *a;
    t_stack *b;
    t_stack *tmp;

    a = stack_init(ac, av);
    tmp = stack_init(ac, av);
    create_nodes(ac, av, tmp);
    sort_stack_ref(tmp);
    a->arr_ref = tmp->arr_ref;
    b = malloc(sizeof(t_stack));
    b->top =NULL;
    b->tail= NULL;
    print_stack("stack_a", a);
    
    
}