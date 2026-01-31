/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjaramil <fjaramil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 19:25:44 by fjaramil          #+#    #+#             */
/*   Updated: 2026/01/25 19:25:44 by fjaramil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_stack *a)
{
	if (a->top->index > a->top->next->index)
		sa(a);
}

void	sort_3(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	if (!a || a->size != 3)
		return ;
	first = a->top->index;
	second = a->top->next->index;
	third = a->top->next->next->index;
	if (first > second && first > third)
		ra(a);
	else if (second > first && second > third)
		rra(a);
	sort_2(a);
}

static int	find_smallest_pos(t_stack *a, int target)
{
	t_node	*curr;
	int		pos;

	curr = a->top;
	pos = 0;
	while (curr)
	{
		if (curr->index == target)
			return (pos);
		curr = curr->next;
		pos++;
	}
	return (-1);
}

static void	bring_min_to_top(t_stack *a, int pos)
{
	if (pos <= a->size / 2)
		while (pos-- > 0)
			ra(a);
	else
		while (pos++ < a->size)
			rra(a);
}

void	sort_4(t_stack *a, t_stack *b)
{
	int	pos;

	pos = find_smallest_pos(a, 0);
	bring_min_to_top(a, pos);
	pb(a, b);
	sort_3(a);
	pa(a, b);
}

void	sort_5(t_stack *a, t_stack *b)
{
	int	pos;

	pos = find_smallest_pos(a, 0);
	bring_min_to_top(a, pos);
	pb(a, b);
	pos = find_smallest_pos(a, 1);
	bring_min_to_top(a, pos);
	pb(a, b);
	sort_3(a);
	pa(a, b);
	pa(a, b);
}
