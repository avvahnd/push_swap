#include "../../include/push_swap.h"

t_strategy	pstrategy(char *arg)
{
	if (ft_strncmp(arg, "--simple", 9) == 0)
		return (SIMPLE);
	if (ft_strncmp(arg, "--medium", 9) == 0)
		return (MEDIUM);
	if (ft_strncmp(arg, "--complex", 9) == 0)
		return (COMPLEX);
	if (ft_strncmp(arg, "--adaptive", 9) == 0)
		return (ADAPTIVE);
	return (INVALID);
}