#include "../include/push_swap.h"

void	sort_stack(t_stack *a, t_stack *b)
{
	if (a->size <= 1)
		return;
	else if (a->size == 2)
		sort_2(a);
	else if (a->size == 3)
		sort_3(a);
	else if (a->size == 4)
		sort_4(a, b);
	else if (a->size == 5)
		sort_5(a, b);
	else
		//radix_sort(a, b);
		chunk_sort(a, b);
}