#include "push_swap.h"

static int	get_chunk_size(int n)
{
	if (n <= 100)
		return (20);
	if (n <= 500)
		return (35);
	return (n / 11 + 10);
}
static void	push_chunks_to_b(t_stack *a, t_stack *b)
{
	int	chunk;
	int	index;

	chunk = get_chunk_size(a->size);
	index = 0;
	while (a->size > 0)
	{
		if (a->top->index <= index)
		{
			pb(a, b);
			rb(b);
			index++;
		}
		else if (a->top->index <= index + chunk)
		{
			pb(a, b);
			index++;
		}
		else
			ra(a);
	}
}

static int find_pos_of_index(t_stack *s, int target)
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

static void	bring_index_to_top_b(t_stack *b, int target)
{
	int	pos;
	int	steps;

	pos = find_pos_of_index(b, target);
	if (pos == -1)
		return;
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

static void	push_back_to_a(t_stack *a, t_stack *b, int n)
{
	int	target;

	target = n - 1;
	while (target >= 0 && b->size > 0)
	{

		bring_index_to_top_b(b, target);
		pa(a, b);

		if (target > 0 && b->size > 0 && b->top->index == target - 1)
		{
			pa(a, b);
			target -= 2;
		}
		else
			target--;
	}
}
void	chunk_sort(t_stack *a, t_stack *b)
{
	int	n;
	
	if (!a || a->size < 2)
		return;
	n = a->size;
	push_chunks_to_b(a, b);
	push_back_to_a(a, b, n);
}
