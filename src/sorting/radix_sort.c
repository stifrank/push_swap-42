#include "push_swap.h"

static int get_max_bits(t_stack *a)
{
   int	max;
   int	bits;

	max = a->size - 1;
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int max_bits;
	int	i;
	int	j;
	int	size;

	if(!a || a->size < 2)
		return;
	max_bits = get_max_bits(a);
	i = 0;
	while (i < max_bits)
	{
		size = a->size;
		j = 0;
		while(j < size)
		{
			if (((a->top->index >> i) & 1) == 0)
				pb(a, b);
			else
				ra(a);
			j++;
		}
		while (b->size > 0)
			pa(a, b);
		i++;
	}
}
