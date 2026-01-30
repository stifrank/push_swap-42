/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_reverse_rotate.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjaramil <fjaramil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 19:25:21 by fjaramil          #+#    #+#             */
/*   Updated: 2026/01/25 19:25:21 by fjaramil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	rra_np(t_stack *a)
{
	t_node	*node;

	if (!a || a->size < 2)
		return;
	node = stack_pop_bottom(a);
	stack_add_top(a, node);
}

static void	rrb_np(t_stack *b)
{
	t_node	*node;

	if (!b || b->size < 2)
		return;
	node = stack_pop_bottom(b);
	stack_add_top(b, node);
}

static void	rrr_np(t_stack *a, t_stack *b)
{
	rra_np(a);
	rrb_np(b);
}
void	rra(t_stack *a)
{
	rra_np(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b)
{
	rrb_np(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	rrr_np(a, b);
	write(1, "rrr\n", 4);
}