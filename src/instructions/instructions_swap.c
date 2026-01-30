/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjaramil <fjaramil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 19:25:28 by fjaramil          #+#    #+#             */
/*   Updated: 2026/01/25 19:25:28 by fjaramil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	sa_np(t_stack *a)
{
	t_node	*first;
	t_node	*second;

	if(!a || a->size < 2)
		return;
	first = a->top;
	second = first->next;

	first->next = second->next;
	if (second->next)
		second->next->prev = first;
 
	second->prev = NULL;
	second->next = first;
	first->prev = second;

	a->top = second;
}
static void	sb_np(t_stack *b)
{
	t_node	*first;
	t_node	*second;

	if (!b || b->size < 2)
		return;
	first = b->top;
	second = first->next;

	first->next = second->next;
	if (second->next)
		second->next->prev = first;

	second->prev = NULL;
	second->next = first;
	first->prev = second;

	b->top = second;
}

static void	ss_np(t_stack *a, t_stack *b)
{
	sa_np(a);
	sb_np(b);
}
void	sa(t_stack *a)
{
	sa_np(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	sb_np(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	ss_np(a, b);
	write(1, "ss\n", 3);
}

