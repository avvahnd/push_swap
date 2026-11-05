#include "../../include/push_swap.h"

int	number(char *str)
{
	int		i;

	if (!str || !*str)
		return (0);
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	overflow(char *str)
{
	long	result;
	long	limit;
	int		i;

	if (!number(str))
		return (0);
	i = 0;
	limit = INT_MAX;
	if (str[i] == '-')
		limit = -(long)INT_MIN;
	if (str[i] == '-' || str[i] == '+')
		i++;
	result = 0;
	while (str[i])
	{
		if (result > (limit - (str[i] - '0')) / 10)
			return (0);
		result = result * 10 + (str[i++] - '0');
	}
	return (1);
}

int	validargs(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!overflow(av[i]))
			return (0);
		i++;
	}
	return (1);
}
