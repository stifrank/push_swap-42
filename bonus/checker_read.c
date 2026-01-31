/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjaramil <fjaramil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 23:53:32 by fjaramil          #+#    #+#             */
/*   Updated: 2026/01/31 23:55:03 by fjaramil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"
#include <stdlib.h>

void	checker_dispatch(t_stack *a, t_stack *b, const char *line);

void	checker_read(t_stack *a, t_stack *b)
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
