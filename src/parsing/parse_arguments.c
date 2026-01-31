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

#include "push_swap.h"

void	parse_arguments(int argc, char **argv, t_stack *a)
{
	int		i;
	int		j;
	long	num;
	int		error;
	char	**tokens;

	i = 1;
	while (i < argc)
	{
		tokens = ps_split_spaces(argv[i]);
		if (!tokens || !tokens[0])
			error_exit();
		j = 0;
		while (tokens[j])
		{
			if (!is_valid_number(tokens[j]))
				(ps_free_split(tokens), error_exit());
			num = safe_atoi(tokens[j], &error);
			if (error || has_duplicate(a, (int)num))
				(ps_free_split(tokens), error_exit());
			stack_add_bottom(a, new_node((int)num));
			j++;
		}
		ps_free_split(tokens);
		i++;
	}
}
