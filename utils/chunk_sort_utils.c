/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 13:00:57 by afaris            #+#    #+#             */
/*   Updated: 2022/08/12 08:33:34 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	update_reference_indexes(t_stack *s, int lt, int gt)
{
	if (lt == s->reference->least_size)
	{
		s->reference->start -= s->offset;
		if (s->reference->start < 0)
			s->reference->start = 0;
		s->reference->least_size = (s->reference->middle + 1)
			- s->reference->start;
	}
	if (gt == s->reference->greatest_size)
	{
		s->reference->end += s->offset;
		if (s->reference->end >= s->reference->size)
			s->reference->end = s->reference->size - 1;
		s->reference->greatest_size = s->reference->end - s->reference->middle;
	}
}

t_node	*find_max(t_node *start)
{
	t_node	*current;

	current = start;
	while (current)
	{
		if (is_max(start, current))
			return (current);
		current = current->next;
	}
	return (current);
}

int	max_location(t_stack *a, t_stack *b)
{
	t_node	*a_bottom_max;
	t_node	*b_bottom_max;
	t_node	*b_max;

	b_bottom_max = find_max(b->bottom_space->start);
	a_bottom_max = a->tail;
	b_max = find_max(b->top);
	if (!b->top)
		return (BOTTOM_STACK_A);
	if (a->bottom_space->size && (a_bottom_max->content > b_max->content))
		return (BOTTOM_STACK_A);
	else
	{
		if (b->bottom_space->size && b_max == b_bottom_max)
			return (BOTTOM_STACK_B);
		else
			return (STACK_B);
	}
}

void	max_move_up(t_stack *a, t_stack *b, int stack)
{
	if (stack == BOTTOM_STACK_B)
	{
		while (b->bottom_space->start)
		{
			move_bottom_to_top(b, STACK_B);
			if (is_max(b->top, b->top))
				break ;
		}
	}
	else if (stack == BOTTOM_STACK_A)
	{
		while (a->bottom_space->start)
		{
			if (is_max(a->bottom_space->start, a->tail))
			{
				move_bottom_to_top(a, STACK_A);
				break ;
			}
			move_bottom_to_top(a, STACK_A);
			push_b(a, b, FALSE);
		}
	}
}
