/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 13:18:11 by afaris            #+#    #+#             */
/*   Updated: 2022/08/12 14:17:52 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *s)
{
	t_node	*current;
	t_node	*tmp;

	current = s->top;
	if (s->reference && s->reference->array)
		free(s->reference->array);
	if (s->reference)
		free(s->reference);
	if (s->bottom_space)
		free(s->bottom_space);
	while (current)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
	if (s)
		free(s);
}

void	chunk_sort(t_stack *a, t_stack *b)
{
	stack_a_migration(a, b);
	stack_b_migration(a, b);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = stack_a_creation(ac, av);
	b = empty_stack_creation();
	if (is_sorted(a))
		exit(EXIT_FAILURE);
	if (ac <= 6)
		mini_sort(a, b, ac);
	else
		chunk_sort(a, b);
	free_stack(a);
	free_stack(b);
	// system("leaks push_swap");
}
