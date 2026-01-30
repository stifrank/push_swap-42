/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjaramil <fjaramil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 19:25:32 by fjaramil          #+#    #+#             */
/*   Updated: 2026/01/25 19:25:32 by fjaramil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	sort_int_array(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size -1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
			j++;
		}
		i++;
	}
}

static void	assign_index_to_nodes(t_stack *a, int *arr, int size)
{
	t_node	*curr;
	int		i;

	curr = a->top;
	while (curr)
	{
		i = 0;
		while (i < size)
		{
			if (curr->value == arr[i])
			{
				curr->index = i;
				break;
			}
			i++;
		}
		curr = curr->next;
	}
	
}

void	assign_indexes(t_stack *a)
{
	int		size;
	int		*arr;
	int		i;
	t_node	*curr;

	size = a->size;
	arr = malloc(sizeof(int) * size);
	if (!arr)
		error_exit();
	curr = a->top;
	i = 0;
	while (curr)
	{
		arr[i++] = curr->value;
		curr = curr->next;
	}
	sort_int_array(arr, size);
	assign_index_to_nodes(a, arr, size);
	free(arr);
}
