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

static void parse_token(t_stack * a, char *token, char **tokens)
{
	long	num;
	int	error;

	if (!is_valid_number(token))
		(ps_free_split(tokens), error_exit());
	num = safe_atoi(token, &error);
	if (error || has_duplicate(a, (int)num))
		(ps_free_split(tokens), error_exit());
	stack_add_bottom(a, new_node((int)num));
}

void	parse_arguments(int argc, char **argv, t_stack *a)
{
	int		i;
	int		j;
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
			parse_token(a, tokens[j], tokens);
			j++;
		}
		ps_free_split(tokens);
		i++;
	}
}
