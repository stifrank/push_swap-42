/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjaramil <fjaramil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 23:55:23 by fjaramil          #+#    #+#             */
/*   Updated: 2026/01/31 23:55:24 by fjaramil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static int	is_sorted_a(t_stack *a)
{
	t_node	*cur;

	if (!a || !a->top)
		return (1);
	cur = a->top;
	while (cur->next)
	{
		if (cur->value > cur->next->value)
			return (0);
		cur = cur->next;
	}
	return (1);
}

static int	is_empty(t_stack *s)
{
	return (!s || s->top == NULL);
}

void	checker_print_result(t_stack *a, t_stack *b)
{
	if (is_sorted_a(a) && is_empty(b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
