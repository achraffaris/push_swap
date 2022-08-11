/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 13:24:24 by afaris            #+#    #+#             */
/*   Updated: 2022/08/11 13:36:55 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define INT_MAX 2147483647
# define INT_MIN 2147483648
# define FALSE 0
# define TRUE 1
# define BOTTOM_STACK_A 0
# define BOTTOM_STACK_B 1
# define STACK_B 2
# define STACK_A 3

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "utils/get_next_line/get_next_line.h"

typedef struct node
{
	int				content;
	int				id;
	struct node		*next;
}	t_node;

typedef struct reference
{
	int				*array;
	int				size;
	int				start;
	int				end;
	int				middle;
	int				least_size;
	int				greatest_size;
	int				lc;
	int				gc;
}	t_reference;

typedef struct bottom_space
{
	int				size;
	t_node			*start;
}	t_bottom_space;

typedef struct stack
{
	t_node			*top;
	t_node			*tail;
	int				n;
	int				size;
	int				offset;
	t_reference		*reference;
	t_bottom_space	*bottom_space;
	t_node			*nodes;
}	t_stack;

void				raise_error(void);
int					ft_atoi(const char *nptr);
int					is_number(char c);
int					is_sign(char c);
void				swap_a(t_stack *s, int muted);
void				rotate_a(t_stack *s, int muted);
void				rev_rotate_a(t_stack *s, int muted);
void				push_a(t_stack *a, t_stack *b, int muted);
void				rotate_b(t_stack *s, int muted);
void				rev_rotate_b(t_stack *s, int muted);
void				push_b(t_stack *a, t_stack *b, int muted);
int					args_duplicated(char **av, int ac);
int					is_sorted(t_stack *s);
int					ft_strlen(char *str);
int					ft_strcmp(char *s1, char *s2);
void				sort_3n(t_stack *s);
int					is_min(t_node *start, t_node *node);
int					is_max(t_node *start, t_node *node);
void				swap_b(t_stack *s, int muted);
void				sort_5n(t_stack *a, t_stack *b);
void				sort_4n(t_stack *a, t_stack *b);
void				mini_sort(t_stack *a, t_stack *b, int ac);
void				insert_node(t_stack *s, t_node *new_node);
void				transfer_top(t_stack *from, t_stack *to);
void				swap_ab(t_stack *a, t_stack *b, int muted);
void				rotate_ab(t_stack *a, t_stack *b, int muted);
void				rev_rotate_ab(t_stack *a, t_stack *b, int muted);
t_node				*get_node_previous(t_stack *s, t_node *node);
t_stack				*empty_stack_creation(void);
void				sort_reference_array(t_stack *copy, t_stack *s);
void				nodes_creation(int ac, char **av, t_stack *s);
void				reference_creation(int ac, char **av, t_stack *s);
t_stack				*stack_a_creation(int ac, char **av);
void				update_reference_indexes(t_stack *s, int lt, int gt);
void				chunk_sort(t_stack *a, t_stack *b);
t_node				*find_max(t_node *start);
int					max_location(t_stack *a, t_stack *b);
void				max_move_up(t_stack *a, t_stack *b, int stack);
void				move_bottom_to_top(t_stack *s, int stack);
void				stack_a_migration(t_stack *a, t_stack *b);
void				stack_b_migration(t_stack *a, t_stack *b);
void				free_stack(t_stack *s);
void				remove_top(t_stack *s);

#endif