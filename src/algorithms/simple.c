#include "../../include/push_swap.h"

void	move_min_to_top(t_stack **a)
{
	int	index;
	int	size;
	int	min_value;

	if (!a || !*a)
		return ;
	index = nindex(*a, find_min(*a));
	size = stack_size(*a);
	min_value = find_min(*a)->value;
	if (index <= size / 2)
	{
		while ((*a)->value != min_value)
			ra(a);
	}
	else
	{
		while ((*a)->value != min_value)
			rra(a);
	}
}

void	simple_sort(t_stack **a, t_stack **b)
{
	if (!a || !*a || is_sorted(*a))
		return ;
	while (*a)
	{
		move_min_to_top(a);
		pb(a, b);
	}
	while (*b)
		pa(a, b);
}