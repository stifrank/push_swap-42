#include "push_swap.h"

void	rr_np(t_stack *a, t_stack *b)
{
	ra_np(a);
	rb_np(b);
}

void	rr(t_stack *a, t_stack *b)
{
	rr_np(a, b);
	write(1, "rr\n", 3);
}
