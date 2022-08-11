#include "../push_swap.h"

int is_number(char c)
{
	return (c >= '0' && c <= '9');
}

int is_sign(char c)
{
	return (c == '+' || c == '-');
}

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	size_t				i;

	i = 0;
	while (s1 && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void	remove_top(t_stack *s)
{
	t_node *top;

	top = s->top;
	if (top)
	{
		s->top = top->next;
		free(top);
		if (!s->top)
			s->tail = NULL;
	}
}