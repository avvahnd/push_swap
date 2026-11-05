#include "../../include/push_swap.h"

int	duplicates(int ac, char **av, int start)
{
	int	i;
	int	j;

	i = start;
	while (i < ac)
	{
		j = i + 1;
		while (j < ac)
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}