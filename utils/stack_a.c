#include "../push_swap.h"



void    swap_a(t_stack *s)
{
    t_node *a;
    t_node *b;

    // a point to the head of the linked nodes.
    // b point to the next node of a, so b is the antecedant of a.
    a = s->top;
    b = a->next;
    ft_swap(&a->content, &b->content);
}

void    push_a(t_stack *a, t_stack *b)
{
    // move stack_a top_node to be the top_node of stack_b
    t_node *top_node;
    top_node = a->top;
    a->top = top_node->next;
    b->top = b->top->next;
    b->top = top_node;
}

void    rotate_a(t_stack *s)
{
    // point the top to the next following node.
    // the old top will be the tail
    // hold the old top, assign the new top to the old_top.next pointer;
    // assign the tail.next to the old_top
    // make the old_top point to Null
    // assign the tail to the old_top

    t_node *old_top;
    old_top = s->top;
    s->top = s->top->next;
    s->tail->next = old_top;
    old_top->next = NULL;
    s->tail = old_top;
}

void    rev_rotate_a(t_stack *s)
{
    t_node *prev_tail_node;
    t_node *current;

    current = s->top;
    // loop trough the linked list and hold the actual node to the prev_tail_node
    // once the current.next is NULL, .i.e the tail of the linked list, we should stop the iteration
    // prev_tail_node will keep holding the previous node before the end one. 
    //  
    while (current)
    {
        prev_tail_node = current;
        current = current->next;
        if (current->next == NULL)
            break ;
    }
    s->tail->next = s->top;
    s->top = s->tail;
    prev_tail_node->next = NULL;
    s->tail = prev_tail_node;
    
    /*
    here we should make the tail of the linked list the top of it.
    and the tail will be previous tail node,
    so previous_tail_node should be found
    and assign its next pointer to NULL,
    */ 
}