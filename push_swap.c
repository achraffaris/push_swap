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
    b = stack_b_init();
    print_stack(a, 4);
    if (ac <= 6)
        mini_sort(a, b, ac);
    else
        chunk_sort(a, b);
    
    while (b->top || bs)
    {
        if (a->top && a->top->next && a->top->content > a->top->next->content)
        {
            int n  = 0, tmp = 0;
            tmp = a->top->content;
            rotate_a(a, FALSE);
            while (tmp > a->top->content)
            {
                push_a(a, b, FALSE);
                n++;
            }
            rev_rotate_a(a, FALSE);
            while (n)
            {
                push_b(a, b, FALSE);
                if (a->top && a->top->next && a->top->content > a->top->next->content)
                    swap_a(a, FALSE);
                n--;
            }
        }
        if (max_found_in(a, b, bs) == STACK_B)
        {
            if (is_max(b, b->top->content))
                push_b(a, b, FALSE);
            else
            {
                push_b(a, b, FALSE);
                rotate_a(a, FALSE);
                bs++;
            }
        }
        else
        {
            while (bs)
            {
                rev_rotate_a(a, FALSE);
                bs--;
                if (is_max_bs(a, bs, a->top->content))
                    break ;
                else
                    push_a(a, b, FALSE);
            }
        }
    }
    print_stack(a, 5);
    if (is_sorted(a))
        printf("\033[32m Sorted successfully!!\n");
    else
        printf("\033[31m NOT sorted!!\n");
}