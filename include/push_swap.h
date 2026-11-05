#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"

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
int	is_sorted(t_stack *stack);

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
int		validargs(int ac, char **av, int start);

int		duplicates(int ac, char **av, int start);

t_stack	*mnode(int value);
void	free_stack(t_stack *stack);
void	append_node(t_stack **stack, t_stack *node);
t_stack	*initstack(int ac, char **av, int start);

typedef enum e_strategy
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE,
	INVALID
}	t_strategy;

t_strategy	pstrategy(char *arg);

t_stack	*find_min(t_stack *stack);
int		nindex(t_stack *stack, t_stack *target);
int		stack_size(t_stack *stack);
int		stack_size(t_stack *stack);

void	move_min_to_top(t_stack **a);
void	simple_sort(t_stack **a, t_stack **b);


#endif