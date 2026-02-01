#include "push_swap.h"

void	ss_np(t_stack *a, t_stack *b)
{
	sa_np(a);
	sb_np(b);
}

void	ss(t_stack *a, t_stack *b)
{
	ss_np(a, b);
	write(1, "ss\n", 3);
}
