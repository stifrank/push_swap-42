/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjaramil <fjaramil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 23:57:34 by fjaramil          #+#    #+#             */
/*   Updated: 2026/01/31 23:57:34 by fjaramil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_chunk_size(int n);
void	bring_index_to_top_b(t_stack *b, int target);

static void	push_chunks_to_b(t_stack *a, t_stack *b)
{
	int	chunk;
	int	index;

	chunk = get_chunk_size(a->size);
	index = 0;
	while (a->size > 0)
	{
		if (a->top->index <= index)
		{
			pb(a, b);
			rb(b);
			index++;
		}
		else if (a->top->index <= index + chunk)
		{
			pb(a, b);
			index++;
		}
		else
			ra(a);
	}
}

static void	push_back_to_a(t_stack *a, t_stack *b, int n)
{
	int	target;

	target = n - 1;
	while (target >= 0 && b->size > 0)
	{
		bring_index_to_top_b(b, target);
		pa(a, b);
		if (target > 0 && b->size > 0 && b->top->index == target - 1)
		{
			pa(a, b);
			target -= 2;
		}
		else
			target--;
	}
}

void	chunk_sort(t_stack *a, t_stack *b)
{
	int	n;

	if (!a || a->size < 2)
		return ;
	n = a->size ;
	push_chunks_to_b(a, b);
	push_back_to_a(a, b, n);
}
