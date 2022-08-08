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

int antecedant_exists(t_stack *s, int start, int end)
{
    t_node *current;

    current = s->top;
    while (current)
    {
        if (current->content > start && current->content <= end)
            return (TRUE);
        current = current->next;
    }
    return (FALSE);
}

int max_found_in_bs(t_stack *s)
{
    int bs;
    t_node *current;

    current = s->tail;
    if (!s->bs)
        return (FALSE);
    bs = s->bs;
    while (bs)
    {
        if (is_max(s, current->content))
            return (TRUE);
        current = current->previous;
        bs--;
    }
    return (FALSE);
}

int main(int ac, char **av)
{
    t_stack *a;
    t_stack *b;
    int bs;
    int stack_b = open("stack_b", O_RDWR, O_APPEND);
    stack_b++;
    bs = 0;
    if (ac <= 1)
        exit(0);
    a = stack_a_init(ac, av);
    b = empty_stack_init();
    if (ac <= 6)
        mini_sort(a, b, ac);
    else
        chunk_sort(a, b);
    while (b->top || a->bs)
    {
        if (max_found_in(a, b, a->bs) == STACK_B)
        {
            if (max_found_in_bs(b))
            {
                while (b->bs)
                {
                    rev_rotate_b(b, FALSE);
                    b->bs--;
                    if (is_max(b, b->top->content))
                        break ;
                }
            }
            if (is_max(b, b->top->content))
                push_a(a, b, FALSE);
            else
            {
                if (a->bs || b->top->content > a->tail->content)
                {
                    push_a(a, b, FALSE);
                    rotate_a(a, FALSE);
                    a->bs++;
                }
                else if (b->top->content < a->tail->content)
                {
                    rotate_b(b, FALSE);
                    b->bs++;
                }
            }
        }
        else
        {
            while (a->bs)
            {
                rev_rotate_a(a, FALSE);
                a->bs--;
                if (is_max_bs(a, bs, a->top->content))
                    break ;
                else
                    push_b(a, b, FALSE);
            }
        }
    }
    // if (is_sorted(a))
    //     printf("\033[32m Sorted successfully!!\n");
    // else
    //     printf("\033[31m NOT sorted!!\n");
}