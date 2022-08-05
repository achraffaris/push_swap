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

int is_max_bs(int bs, t_stack *s)
{
    t_node *current;

    current = s->tail;
    while (bs)
    {
        if (current->content > s->top->content)
            return (FALSE);
        bs--;
    }
    return (TRUE);
}

int main(int ac, char **av)
{
    t_stack *a;
    t_stack *b;
    int bs;

    bs = 0;
    if (ac <= 1)
        exit(0);
    a = stack_a_init(ac, av);
    b = stack_b_init();
    if (ac <= 6)
        mini_sort(a, b, ac);
    else
        chunk_sort(a, b);
    while (b->top || bs)
    {
        if (is_max(b, b->top->content))
            push_b(a, b, FALSE);
        while (bs && )
        {
            rev_rotate_a(a, FALSE);
            if (a->top && a->top->next && a->top->content > a->top->next->content)
                swap_a(a, FALSE);
            bs--;
        }
        if (!bs && b->top && a->tail && b->top->content > a->tail->content)
        {
            push_b(a, b, FALSE);
            rotate_a(a, FALSE);
        }
        else
        {
            while (b->top && (!is_max(b, b->top->content)))
            {
                push_b(a, b, FALSE);
                if (a->top && a->top->next && a->top->content > a->top->next->content)
                    swap_a(a, FALSE);
                rotate_a(a, FALSE);
                
                bs++;
            }
        }
    }
    print_stack("stack_a", a);
    if (is_sorted(a))
        printf("\033[32m Sorted successfully!!\n");
    else
        printf("\033[31m NOT sorted!!\n");
    
}