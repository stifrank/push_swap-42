/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjaramil <fjaramil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 19:26:01 by fjaramil          #+#    #+#             */
/*   Updated: 2026/01/25 19:26:01 by fjaramil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	has_duplicate(t_stack *a, int value)
{
	t_node	*curr;

	curr = a->top;
	while (curr)
	{
		if (curr->value == value)
			return(1);
		curr = curr->next;
	}
	return (0);
}