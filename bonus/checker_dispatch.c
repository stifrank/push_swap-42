/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_dispatch.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjaramil <fjaramil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 23:51:32 by fjaramil          #+#    #+#             */
/*   Updated: 2026/01/31 23:53:00 by fjaramil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static int	is_cmd(const char *line, const char *cmd)
{
	int	i;

	i = 0;
	while (line[i] && cmd[i] && line[i] == cmd[i])
		i++;
	return (line[i] == '\0' && cmd[i] == '\0');
}

void	checker_dispatch(t_stack *a, t_stack *b, const char *line)
{
	if (is_cmd(line, "sa\n") || is_cmd(line, "sa"))
		sa_np(a);
	else if (is_cmd(line, "sb\n") || is_cmd(line, "sb"))
		sb_np(b);
	else if (is_cmd(line, "ss\n") || is_cmd(line, "ss"))
		ss_np(a, b);
	else if (is_cmd(line, "pa\n") || is_cmd(line, "pa"))
		pa_np(a, b);
	else if (is_cmd(line, "pb\n") || is_cmd(line, "pb"))
		pb_np(a, b);
	else if (is_cmd(line, "ra\n") || is_cmd(line, "ra"))
		ra_np(a);
	else if (is_cmd(line, "rb\n") || is_cmd(line, "rb"))
		rb_np(b);
	else if (is_cmd(line, "rr\n") || is_cmd(line, "rr"))
		rr_np(a, b);
	else if (is_cmd(line, "rra\n") || is_cmd(line, "rra"))
		rra_np(a);
	else if (is_cmd(line, "rrb\n") || is_cmd(line, "rrb"))
		rrb_np(b);
	else if (is_cmd(line, "rrr\n") || is_cmd(line, "rrr"))
		rrr_np(a, b);
	else
		error_exit();
}
