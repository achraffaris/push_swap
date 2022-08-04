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
int main(int ac, char **av)
{
    t_stack *a;
    t_stack *b;
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
        if (tail_space && (!antecedant_exists(b, b->tail->content, a->top->content)) && a->top)
        {
            tail_space--;
            rev_rotate_b(b, FALSE);
            push_b(a, b, FALSE);
        }
        if ((b->top && b->top->next && b->top->content > b->top->next->content) || b->stack_size == 1)
        {
            if (tail_space && b->tail->content > b->top->content && b->stack_size > 1)
            {
                rev_rotate_b(b, FALSE);
                tail_space--;
            }
            push_b(a, b, FALSE);
            if (a->top->content > a->tail->content)
                rotate_a(a, FALSE);
        }
        else
        {
            rotate_b(b, FALSE);
            tail_space++;
        }
    }
    print_stack("stack_a", a);
    print_stack("stack_b", b);
    if (is_sorted(a))
        printf("\033[32m Sorted successfully!!\n");
    else
        printf("\033[31m NOT sorted!!\n");
    
}