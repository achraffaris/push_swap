#include "../push_swap.h"

void    ft_swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

int is_number(char c)
{
	return (c >= '0' && c <= '9');
}

int is_sign(char c)
{
	return (c == '+' || c == '-');
}
