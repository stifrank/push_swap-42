#include "push_swap.h"
#include "get_next_line.h"
#include <stdlib.h>

void  checker_dispatch(t_stack *a, t_stack *b, const char *line);

void	checker_read(t_stack *a,t_stack *b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		checker_dispatch(a, b, line);
		free(line);
		line = get_next_line(0);
	}
}