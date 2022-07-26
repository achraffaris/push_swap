/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:48:00 by afaris            #+#    #+#             */
/*   Updated: 2022/08/11 21:23:53 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*empty_stack_creation(void)
{
	t_stack	*s;

	s = malloc(sizeof(t_stack));
	if (!s)
		raise_error();
	s->tail = NULL;
	s->top = NULL;
	s->bottom_space = malloc(sizeof(t_bottom_space));
	s->bottom_space->size = 0;
	s->bottom_space->start = NULL;
	s->reference = NULL;
	if (!s->bottom_space)
		raise_error();
	s->size = 0;
	return (s);
}

void	sort_reference_array(t_stack *copy, t_stack *s)
{
	int		i;
	t_stack	*tmp;

	tmp = empty_stack_creation();
	i = 0;
	while (copy->top)
	{
		if (is_min(copy->top, copy->top))
		{
			s->reference->array[i] = copy->top->id;
			transfer_top(copy, tmp);
			i++;
		}
		else
			rotate_a(copy, TRUE);
	}
	free_stack(copy);
	free_stack(tmp);
}

void	nodes_creation(int ac, char **av, t_stack *s)
{
	int		i;
	int		j;
	t_node	*current;

	i = 1;
	j = ac - 1;
	current = malloc(sizeof(t_node));
	s->top = current;
	while (av[i])
	{
		current->id = ac - 1;
		current->content = ft_atoi(av[i]);
		if (i == 1)
			s->top = current;
		if (i == j)
		{
			current->next = NULL;
			s->tail = current;
		}
		else
			current->next = malloc(sizeof(t_node));
		current = current->next;
		i++;
		ac--;
	}
}

void	reference_creation(int ac, char **av, t_stack *s)
{
	t_stack	*copy;

	copy = empty_stack_creation();
	nodes_creation(ac, av, copy);
	s->reference = malloc(sizeof(t_reference));
	if (!s->reference)
		raise_error();
	s->reference->size = ac - 1;
	s->reference->array = malloc(sizeof(int) * s->reference->size);
	if (!s->reference->array)
		raise_error();
	s->reference->middle = s->reference->size / 2;
	s->reference->start = s->reference->middle - s->offset;
	if (s->reference->start < 0)
		s->reference->start = 0;
	s->reference->end = s->reference->middle + s->offset;
	if (s->reference->end >= s->reference->size)
		s->reference->end = s->reference->size - 1;
	s->reference->least_size = (s->reference->middle + 1) - s->reference->start;
	s->reference->greatest_size = s->reference->end - s->reference->middle;
	s->reference->gc = 0;
	s->reference->lc = 0;
	copy->size = s->size;
	sort_reference_array(copy, s);
}

t_stack	*stack_a_creation(int ac, char **av)
{
	t_stack	*s;

	s = malloc(sizeof(t_stack));
	if (ac == 1)
		exit(EXIT_FAILURE);
	if (args_duplicated(av, ac) || !s)
		raise_error();
	s->size = ac - 1;
	if (s->size <= 10)
		s->n = 5;
	else if (s->size <= 150)
		s->n = 8;
	else
		s->n = 16;
	s->offset = s->size / s->n;
	s->bottom_space = malloc(sizeof(t_bottom_space));
	if (!s->bottom_space)
		raise_error();
	s->bottom_space->start = NULL;
	nodes_creation(ac, av, s);
	reference_creation(ac, av, s);
	return (s);
}
