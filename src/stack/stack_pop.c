/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjaramil <fjaramil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 19:25:57 by fjaramil          #+#    #+#             */
/*   Updated: 2026/01/25 19:25:57 by fjaramil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_node *stack_pop_top(t_stack *stack)
{
   t_node	*node;

   if (!stack || stack->size == 0)
		return (NULL);
	node = stack->top;
	stack->top = node->next;
	if (stack->top)
		stack->top->prev = NULL;
	else
		stack->bottom = NULL;
	node->next = NULL;
	node->prev = NULL;
	stack->size--;
	return (node);
}

t_node *stack_pop_bottom(t_stack *stack)
{
	t_node	*node;

	if (!stack || stack->size == 0)
		return (NULL);
	node = stack->bottom;
	stack->bottom = node->prev;
	if (stack->bottom)
		stack->bottom->next = NULL;
	else
		stack->top = NULL;
	node->next = NULL;
	node->prev = NULL;
	stack->size--;
	return (node);
}