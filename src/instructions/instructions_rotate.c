/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjaramil <fjaramil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 19:25:25 by fjaramil          #+#    #+#             */
/*   Updated: 2026/01/25 19:25:25 by fjaramil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_np(t_stack *a)
{
	t_node	*node;

	if (!a || a->size < 2)
		return ;
	node = stack_pop_top(a);
	stack_add_bottom(a, node);
}

void	rb_np(t_stack *b)
{
	t_node	*node;

	if (!b || b->size < 2)
		return ;
	node = stack_pop_top(b);
	stack_add_bottom(b, node);
}

void	ra(t_stack *a)
{
	ra_np(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	rb_np(b);
	write(1, "rb\n", 3);
}
