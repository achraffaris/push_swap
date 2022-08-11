/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:55:56 by afaris            #+#    #+#             */
/*   Updated: 2022/08/11 12:59:50 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_max(t_node *start, t_node *node)
{
	t_node	*current;

	current = start;
	while (current)
	{
		if (current->content > node->content)
			return (FALSE);
		current = current->next;
	}
	return (TRUE);
}

int	is_min(t_node *start, t_node *node)
{
	t_node	*current;

	current = start;
	while (current)
	{
		if (current->content < node->content)
			return (FALSE);
		current = current->next;
	}
	return (TRUE);
}
