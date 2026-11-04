#include "../../include/push_swap.h"

t_stack	*stacklast(t_stack *stack)
{
	t_stack	*last;

	if (!stack)
		return (NULL);
	last = stack;
	while (last->next)
		last = stack->next;
	return (last);
}
