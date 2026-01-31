/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjaramil <fjaramil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 22:34:43 by fjaramil          #+#    #+#             */
/*   Updated: 2025/10/28 22:34:43 by fjaramil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include "push_swap.h"
#include <stdlib.h>

static int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

static int	count_words(const char *s)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && is_space(s[i]))
			i++;
		if (s[i])
		{
			count++;
			while (s[i] && !is_space(s[i]))
				i++;
		}
	}
	return (count);
}

static char	*dup_word(const char *s, int start, int len)
{
	char	*word;
	int		i;

	word = (char *)malloc((size_t)len + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[start + i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	free_partial(char **arr, int filled)
{
	int	i;

	i = 0;
	while (i < filled)
		free(arr[i++]);
	free(arr);
}

char	**ps_split_spaces(const char *s)
{
	char	**arr;
	int		i;
	int		k;
	int		start;

	if (!s)
		return (NULL);
	arr = (char **)malloc(sizeof(char *) * ((size_t)count_words(s) + 1));
	if (!arr)
		return (NULL);
	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] && is_space(s[i]))
			i++;
		if (!s[i])
			break ;
		start = i;
		while (s[i] && !is_space(s[i]))
			i++;
		arr[k] = dup_word(s, start, i - start);
		if (!arr[k])
			return (free_partial(arr, k), NULL);
		k++;
	}
	arr[k] = NULL;
	return (arr);
}

void	ps_free_split(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}
