#include "../../include/push_swap.h"

t_stack	*mnode(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	free_stack(t_stack *stack)
{
	t_stack	*next;

	while (stack)
	{
		next = stack->next;
		free(stack);
		stack = next;
	}
}

void	append_node(t_stack **stack, t_stack *node)
{
	t_stack	*last;

	if (!*stack)
	{
		*stack = node;
		return ;
	}
	last = stacklast(*stack);
	last->next = node;
	node->prev = last;
}

t_stack	*initstack(int ac, char **av, int start)
{
	t_stack	*stack;
	t_stack	*node;
	int		i;

	stack = NULL;
	i = start;
	while (i < ac)
	{
		node = mnode(ft_atoi(av[i]));
		if (!node)
		{
			free_stack(stack);
			return (NULL);
		}
		append_node(&stack, node);
		i++;
	}
	return (stack);
}
