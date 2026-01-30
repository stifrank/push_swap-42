#include "../include/push_swap.h"
#include <stdio.h> // DEBUG solo un momento

static int	get_chunk_size(int n)
{
	if (n <= 100)
		return (20);
	if (n <= 500)
		return (45);
	return (n / 11 + 10);
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
static int	find_first_leq(t_stack *a, int limit)
{
	t_node	*cur;
	int		pos;

	cur = a->top;
	pos = 0;
	while (cur)
	{
		if (cur->index <= limit)
			return (pos);
		cur = cur->next;
		pos++;
	}
	return (-1);
}

static int	find_last_leq(t_stack *a, int limit)
{
	t_node	*cur;
	int		pos;
	int		last;

	cur = a->top;
	pos = 0;
	last = -1;
	while (cur)
	{
		if (cur->index <= limit)
			last = pos;
		cur = cur->next;
		pos++;
	}
	return (last);
}
static void	push_chunks_to_b(t_stack *a, t_stack *b)
{
	int	chunk;
	int	limit;
	int	pushed;

	chunk = get_chunk_size(a->size);
	limit = chunk - 1;
	pushed = 0;

	while (a->size > 0)
	{
		if (a->top->index <= limit)
		{
			pb(a, b);
			pushed++;

			// opcional: si es de la mitad baja del chunk, rota B
			if (b->top->index <= limit - (chunk / 2))
				rb(b);

			// cuando hemos empujado "chunk" elementos, ampliamos el rango
			if (pushed == chunk)
			{
				limit += chunk;
				pushed = 0;
			}
		}
		else
		{
			int	pos_top = find_first_leq(a, limit);
			int	pos_bot = find_last_leq(a, limit);
			int	steps;

			// si por lo que sea no hay ninguno <= limit, ampliamos rango
			if (pos_top == -1)
			{
				limit += chunk;
				pushed = 0;
				continue;
			}

			// distancia desde arriba = pos_top
			// distancia desde abajo = (a->size - 1 - pos_bot) + 1 = a->size - pos_bot
			if (pos_top <= (a->size - pos_bot))
			{
				while (pos_top-- > 0)
					ra(a);
			}
			else
			{
				steps = a->size - pos_bot;
				while (steps-- > 0)
					rra(a);
			}
		}

	}
}

static void	push_back_to_a(t_stack *a, t_stack *b, int n)
{
	int	target;
	int pos_t1;

	target = n - 1;
	while (target >= 0 && b->size > 0)
	{
		if (target > 0)
			pos_t1 = find_pos_of_index(b, target - 1);
		else
			pos_t1 = -1;

		bring_index_to_top_b(b, target);
		pa(a, b);

		if (pos_t1 == 0 && target > 0 && b->size > 0)
		{
			pa(a, b);
			sa(a);
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