/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjaramil <fjaramil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 19:26:11 by fjaramil          #+#    #+#             */
/*   Updated: 2026/01/25 19:26:11 by fjaramil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

long	safe_atoi(char *str, int *error)
{
	long	result;
	int		sign;
	int		i;

	*error = 0;
	result = 0;
	sign = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		result = result * 10 + (str[i] - '0');
		if ((sign > 0 && result > INT_MAX) || (sign < 0 && - result < INT_MIN))
		{
			*error = 1;
			return (0);
		}
		i++;
	}
	return (result * sign);
}
