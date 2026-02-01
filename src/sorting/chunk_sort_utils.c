#include "push_swap.h"

int	get_chunk_size(int n)
{
	if (n <= 100)
		return (20);
	if (n <= 500)
		return (35);
	return (n / 11 + 10);
}

static int	find_pos_of_index(t_stack *s, int target)
{
	t_node	*cur;
	int		pos;

	cur = s->top;
	pos = 0;
	while (cur)
	{
		if (cur->index == target)
			return (pos);
		cur = cur->next;
		pos++;
	}
	return (-1);
}

void	bring_index_to_top_b(t_stack *b, int target)
{
	int	pos;
	int	steps;

	pos = find_pos_of_index(b, target);
	if (pos == -1)
		return ;
	if (pos <= b->size / 2)
	{
		while (pos-- > 0)
			rb(b);
	}
	else
	{
		steps = b->size - pos;
		while (steps--)
			rrb(b);
	}
}
