/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjaramil <fjaramil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 19:25:50 by fjaramil          #+#    #+#             */
/*   Updated: 2026/01/25 19:25:50 by fjaramil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_add_bottom(t_stack *stack, t_node *new)
{
	if (!stack || !new)
		return;
	if (stack->size == 0)
	{
		stack->top = new;
		stack->bottom = new;
	}
	else
	{
		new->prev = stack->bottom;
		stack->bottom->next = new;
		stack->bottom = new;
	}
	stack->size++;
}
void	stack_add_top(t_stack *stack, t_node *new)
{
	if(!stack || !new)
		return;
	if (stack->size == 0)
	{
		stack->top = new;
		stack->bottom = new;
	}
	else
	{
		new->next = stack->top;
		stack->top->prev = new;
		stack->top = new;
	}
	stack->size++;
}