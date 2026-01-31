/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjaramil <fjaramil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 19:25:12 by fjaramil          #+#    #+#             */
/*   Updated: 2026/01/25 19:25:12 by fjaramil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	pb_np(t_stack *a, t_stack *b)
{
	t_node	*node;

	if (!a || a->size == 0)
		return;
	node = stack_pop_top(a);
	stack_add_top(b, node);
}

void	pa_np(t_stack *a, t_stack *b)
{
	t_node	*node;

	if (!b || b->size == 0)
		return;
	node = stack_pop_top(b);
	stack_add_top(a, node);
}
void	pa(t_stack *a, t_stack *b)
{
	pa_np(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	pb_np(a, b);
	write(1, "pb\n", 3);
}
