#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

int		swap(t_stack **stack);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

int		push(t_stack **src, t_stack **dst);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);

t_stack	*stacklast(t_stack *stack);

int		rotate(t_stack **stack);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

int		rrotate(t_stack **stack);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

int		number(char *str);
int		overflow(char *str);
int		validargs(int ac, char **av);


#endif