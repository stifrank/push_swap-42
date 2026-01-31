#include "../include/push_swap.h"

void	free_stack(t_stack *s)
{
	t_node	*tmp;

	while (s->top)
	{
		tmp = s->top;
		s->top = s->top->next;
		free(tmp);
	}
	s->bottom = NULL;
	s->size = 0;
}
