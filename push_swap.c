#include "push_swap.h"

// ./ps 2 5 0 1 

// need to be optimized


void    print_stack(t_stack *s, int fd)
{
    t_node *head;

    head = s->top;
    fd++;
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
    if (ac <= 1)
        exit(0);
    a = stack_a_init(ac, av);
    b = empty_stack_init();
    if (ac <= 6)
        mini_sort(a, b, ac);
    else
        chunk_sort(a, b);
    // if (is_sorted(a))
    //     printf("\033[32m Sorted successfully!!\n");
    // else
    //     printf("\033[31m NOT sorted!!\n");
}