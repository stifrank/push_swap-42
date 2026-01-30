/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjaramil <fjaramil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 19:26:07 by fjaramil          #+#    #+#             */
/*   Updated: 2026/01/25 19:26:07 by fjaramil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	parse_arguments(int argc, char **argv, t_stack *a)
{
	int		i;
	long	num;
	int		error;

	i = 1;
	while (i < argc)
	{
		if (!is_valid_number(argv[i]))
			error_exit();
		num = safe_atoi(argv[i], &error);
		if (error)
			error_exit();
		if (has_duplicate(a, (int)num))
			error_exit();
		stack_add_bottom(a, new_node((int)num));
		i++;
	}
}
