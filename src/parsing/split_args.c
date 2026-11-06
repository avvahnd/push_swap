#include "../../include/push_swap.h"

static int	count_words(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
			count++;
		i++;
	}
	return (count);
}

static int	countnum(int ac, char **av, int start)
{
	int	total;
	int	words;

	total = 0;
	while (start < ac)
	{
		words = count_words(av[start]);
		if (!words)
			return (-1);
		total += words;
		start++;
	}
	return (total);
}

void	free_args(char **args)
{
	int	i;

	if (!args)
		return ;
	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
}

static int	append_split(char **args, int *pos, char *str)
{
	char	**split;
	int		i;

	split = ft_split(str, ' ');
	if (!split)
		return (0);
	i = 0;
	while (split[i])
	{
		args[*pos] = split[i];
		(*pos)++;
		i++;
	}
	args[*pos] = NULL;
	free(split);
	return (1);
}

char	**split_args(int ac, char **av, int start)
{
	char	**args;
	int		total;
	int		pos;

	total = countnum(ac, av, start);
	if (total <= 0)
		return (NULL);
	args = malloc(sizeof(char *) * (total + 1));
	if (!args)
		return (NULL);
	args[0] = NULL;
	pos = 0;
	while (start < ac)
	{
		if (!append_split(args, &pos, av[start++]))
			return (free_args(args), NULL);
	}
	return (args);
}

