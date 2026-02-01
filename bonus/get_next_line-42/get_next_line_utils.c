/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjaramil <fjaramil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 18:16:07 by fjaramil          #+#    #+#             */
/*   Updated: 2025/12/17 18:16:07 by fjaramil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	ch;

	if (!s)
		return (NULL);
	ch = (unsigned char)c;
	while (*s)
	{
		if ((unsigned char)*s == ch)
			return ((char *)s);
		s++;
	}
	if (ch == '\0')
		return ((char *)s);
	return (NULL);
}

static void	copy_block(char *dst, const char *src, size_t start, size_t len)
{
	size_t	k;

	k = 0;
	while (k < len)
	{
		dst[start + k] = src[k];
		k++;
	}
}

char	*ft_strjoin_free(char *s1, const char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*dst;

	len1 = 0;
	if (s1)
		len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	dst = (char *)malloc(len1 + len2 + 1);
	if (!dst)
		return (free(s1), NULL);
	copy_block(dst, s1, 0, len1);
	copy_block(dst, s2, len1, len2);
	dst[len1 + len2] = '\0';
	free(s1);
	return (dst);
}
