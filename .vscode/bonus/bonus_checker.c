/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 13:17:04 by afaris            #+#    #+#             */
/*   Updated: 2022/08/11 21:45:45 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	exec_actions(t_stack *a, t_stack *b, char *action)
{
	if (ft_strcmp(action, SA) == 0)
		swap_a(a, TRUE);
	else if (ft_strcmp(action, SB) == 0)
		swap_b(b, TRUE);
	else if (ft_strcmp(action, RA) == 0)
		rotate_a(a, TRUE);
	else if (ft_strcmp(action, RB) == 0)
		rotate_b(b, TRUE);
	else if (ft_strcmp(action, RRA) == 0)
		rev_rotate_a(a, TRUE);
	else if (ft_strcmp(action, RRB) == 0)
		rev_rotate_b(b, TRUE);
	else if (ft_strcmp(action, SS) == 0)
		swap_ab(a, b, TRUE);
	else if (ft_strcmp(action, RRR) == 0)
		rotate_ab(a, b, TRUE);
	else if (ft_strcmp(action, PB) == 0)
		push_b(a, b, TRUE);
	else if (ft_strcmp(action, PA) == 0)
		push_a(a, b, TRUE);
	else
		raise_error();
}

void	actions_listener(t_stack *a, t_stack *b)
{
	char	*buff;

	buff = get_next_line(0);
	while (buff)
	{
		exec_actions(a, b, buff);
		free(buff);
		buff = get_next_line(0);
	}
	if (is_sorted(a) && (!b->top))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = stack_a_creation(ac, av);
	b = empty_stack_creation();
	actions_listener(a, b);
	free_stack(a);
	free_stack(b);
}
