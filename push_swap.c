#include "push_swap.h"

// ./ps 2 5 0 1 

// need to be optimized


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
    int tmp;
    int n;
    n = 0;
    int tail_space;

    tail_space = 0;
    if (ac <= 1)
        exit(0);
    a = stack_a_init(ac, av);
    b = stack_b_init();
    if (ac <= 6)
        mini_sort(a, b, ac);
    else
        chunk_sort(a, b);
    while (b->top)
    {
        if ((b->top && b->top->next && b->top->content > b->top->next->content) || b->stack_size == 1)
        {
            if (tail_space > 0)
            {
                if (b->tail->content > b->top->content && b->stack_size > 1)
                {
                    rev_rotate_b(b, FALSE);
                    tail_space--;
                }
            }
            push_b(a, b, FALSE);
            if (a->top->content > a->tail->content)
                rotate_a(a, FALSE);
            if (a->top && a->top->next && a->top->content > a->top->next->content)
            {
                tmp = a->top->content;
                push_a(a, b, FALSE);
                while (tmp > a->top->content)
                {
                    rotate_a(a, FALSE);
                    n++;
                }
                push_b(a, b, FALSE);
                while (n > 0)
                {
                    rev_rotate_a(a, FALSE);
                    n--;
                }
            }
        }
        else
        {
            rotate_b(b, FALSE);
            tail_space++;
        }
    }
    print_stack("stack a", a);
    if (is_sorted(a))
        printf("\033[32m Sorted successfully!!\n");
    else
        printf("\033[31m NOT sorted!!\n");
    
}