#include "push_swap.h"

void	rrr_np(t_stack *a, t_stack *b)
{
	rra_np(a);
	rrb_np(b);
}

void	rrr(t_stack *a, t_stack *b)
{
	rrr_np(a, b);
	write(1, "rrr\n", 4);
}
