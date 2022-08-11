/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:54:31 by afaris            #+#    #+#             */
/*   Updated: 2022/08/11 12:57:27 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_a(t_stack *s, int muted)
{
	t_node	*a;
	t_node	*b;

	if (s->top && s->top->next)
	{
		a = s->top;
		b = a->next;
		a->next = b->next;
		b->next = a;
		s->top = b;
		if (s->size == 2)
		{
			s->tail = a;
			s->tail->next = NULL;
		}
		if (!muted)
			write(1, "sa\n", 3);
	}
}

void	push_a(t_stack *a, t_stack *b, int muted)
{
	if (b->top)
	{
		transfer_top(b, a);
		if (!muted)
			write(1, "pa\n", 3);
	}
}

void	rotate_a(t_stack *s, int muted)
{
	t_node	*old_top;
	t_node	*old_tail;

	if (s->size <= 2)
		swap_a(s, muted);
	else
	{
		old_top = s->top;
		old_tail = s->tail;
		s->top = old_top->next;
		old_tail->next = old_top;
		s->tail = old_top;
		s->tail->next = NULL;
		if (!muted)
			write(1, "ra\n", 3);
	}
}

void	rev_rotate_a(t_stack *s, int muted)
{
	t_node	*old_top;
	t_node	*tail_previous;

	if (s->size <= 2)
		swap_a(s, muted);
	else
	{
		tail_previous = get_node_previous(s, s->tail);
		old_top = s->top;
		s->top = s->tail;
		s->top->next = old_top;
		s->tail = tail_previous;
		s->tail->next = NULL;
		if (!muted)
			write(1, "rra\n", 4);
	}
}
