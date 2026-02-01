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
#include <stdlib.h>

int	is_space(char c);
int	count_words(const char *s);

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

static int	add_word(char **arr, const char *s, int *i, int *k)
{
	int	start;

	while (s[*i] && is_space(s[*i]))
		(*i)++;
	if (!s[*i])
		return (0);
	start = *i;
	while (s[*i] && !is_space(s[*i]))
		(*i)++;
	arr[*k] = dup_word(s, start, *i - start);
	if (!arr[*k])
		return (free_partial(arr, *k), -1);
	(*k)++;
	return (1);
}

char	**ps_split_spaces(const char *s)
{
	char	**arr;
	int		i;
	int		k;
	int		status;

	if (!s)
		return (NULL);
	arr = (char **)malloc(sizeof(char *) * ((size_t)count_words(s) + 1));
	if (!arr)
		return (NULL);
	i = 0;
	k = 0;
	status = 1;
	while (status > 0)
		status = add_word(arr, s, &i, &k);
	if (status < 0)
		return (NULL);
	arr[k] = NULL;
	return (arr);
}
