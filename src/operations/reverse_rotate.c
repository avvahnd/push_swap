#include "../../include/push_swap.h"

int	rrotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*plast;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	first = *stack;
	last = stacklast(first);
	plast = last->prev;
	*stack = last;
	(*stack)->prev = NULL;
	last->next = first;
	first->prev = last;
	plast->next = NULL;
	return (1);
}

void	rra(t_stack **a)
{
	if (rrotate(a))
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	if (rrotate(b))
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	int	rrotated_a;
	int	rrotated_b;

	rrotated_a = rrotate(a);
	rrotated_b = rrotate(b);
	if (rrotated_a || rrotated_b)
		write(1, "rrr\n", 4);
}