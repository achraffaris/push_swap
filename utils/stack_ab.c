#include "../push_swap.h"

t_node  *extract_node(t_stack *s)
{
    t_node *old_node;
    // return Null if the given stack is empty
    if (!s->top)
        return (NULL);
    old_node = s->top;
    s->top = old_node->next;
    // if the given stack becomes empty, s.top should be Null. But,
    // s.tail may reserve the old node. it should be Null too
    if (!s->top)
        s->tail = NULL;
    return (old_node);
}

void    insert_node(t_stack *s, t_node *new_node)
{
    t_node *old_node;

    old_node = s->top;
    // if the given stack is not empty, simply re-link s.top with
    // the given node, this final should point to the old node, 
    // and finally the antecedant of the old node should be the given node 
    if (s->top)
    {
        new_node->next = old_node;
        old_node->previous = NULL;
        s->top = new_node;
    }
    // else if the given stack is empty than make the s.top and s.tail point to 
    // the given node, since the stack is empty, the new node should point to Null
    else
    {
        s->top = new_node;
        s->tail = new_node;
        new_node->next = NULL;
    }
}

void    swap_ab(t_stack *a, t_stack *b, int muted)
{
    swap_a(a, TRUE);
    swap_b(b, TRUE);
    if (!muted)
        write(1, "ss\n", 3);
}

void    rotate_ab(t_stack *a, t_stack *b, int muted)
{
    rotate_a(a, TRUE);
    rotate_b(b, TRUE);
    if (!muted)
        write(1, "rr\n", 3);
}

void    rev_rotate_ab(t_stack *a, t_stack *b, int muted)
{
    rev_rotate_a(a, TRUE);
    rev_rotate_b(b, TRUE);
    if (!muted)
        write(1, "rrr\n", 4);
}