#include "../../include/push_swap.h"

int	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	first = *stack;
	last = stacklast(first);
	*stack = first->next;
	(*stack)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	return (1);
}

void	ra(t_stack **a)
{
	if (rotate(a))
		write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	if (rotate(b))
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	int	rotated_a;
	int	rotated_b;

	rotated_a = rotate(a);
	rotated_b = rotate(b);
	if (rotated_a || rotated_b)
		write(1, "rr\n", 3);
}