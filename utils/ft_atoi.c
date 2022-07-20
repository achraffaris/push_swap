#include "../push_swap.h"

int valid_interger(long long res, int s)
{
    if (res > INT_MAX && s == 1)
		raise_error();
	else if (res > INT_MIN && s == -1)
		raise_error();
    return (res * s);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	long long	res;
	int	s;

	s = 1;
	res = 0;
	i = 0;
	if (is_sign(nptr[i]) && is_number(nptr[i + 1]))
	{
		if (nptr[i] == '-')
			s = -1;
		i++;
	}
	while (nptr[i])
	{
		if (!is_number(nptr[i]))
        	raise_error();
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	return (valid_interger(res, s));
}