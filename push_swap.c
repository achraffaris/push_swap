#include "push_swap.h"

// ./ps 2 5 0 1 

// need to be optimized


void    print_stack(t_stack *s, char *title)
{
    t_node *head;

    head = s->top;
    printf("----------%s-----------\n", title);
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

    a = stack_a_creation(ac, av);
    b = empty_stack_creation();
    if (is_sorted(a))
        exit(EXIT_FAILURE);
    // if (ac <= 6)
    //     mini_sort(a, b, ac);
    // else
    //     chunk_sort(a, b);
    // if (is_sorted(a))
    //     printf("\033[32m Sorted successfully!!\n");
    // else
    //     printf("\033[31m NOT sorted!!\n");
}