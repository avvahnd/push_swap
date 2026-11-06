#include "../../include/push_swap.h"

void	assign_indices(t_stack *stack)
{
	t_stack	*current;
	t_stack	*compare;
	int		index;

	current = stack;
	while (current)
	{
		index = 0;
		compare = stack;
		while (compare)
		{
			if (compare->value < current->value)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
}

void	radix_pass(t_stack **a, t_stack **b, int bit)
{
	int	size;
	int	i;

	size = stack_size(*a);
	i = 0;
	while (i < size)
	{
		if (((*a)->index >> bit) & 1)
			ra(a);
		else
			pb(a, b);
		i++;
	}
	while (*b)
		pa(a, b);
}

void	radix_sort(t_stack **a, t_stack **b)
{
	int	bit;
	int	size;

	if (!a || !*a || is_sorted(*a))
		return ;
	assign_indices(*a);
	size = stack_size(*a);
	bit = 0;
	while ((size - 1) >> bit)
	{
		radix_pass(a, b, bit);
		bit++;
	}
}
