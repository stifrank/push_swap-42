#include "push_swap.h"

int	find_smallest_pos(t_stack *a, int target)
{
	t_node	*curr;
	int		pos;

	curr = a->top;
	pos = 0;
	while (curr)
	{
		if (curr->index == target)
			return (pos);
		curr = curr->next;
		pos++;
	}
	return (-1);
}

void	bring_min_to_top(t_stack *a, int pos)
{
	if (pos <= a->size / 2)
		while (pos-- > 0)
			ra(a);
	else
		while (pos++ < a->size)
			rra(a);
}
