/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjaramil <fjaramil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 18:16:12 by fjaramil          #+#    #+#             */
/*   Updated: 2025/12/17 18:16:12 by fjaramil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	fill_until_newline(int fd, char **stash)
{
	ssize_t	bytes;
	char	*buf;

	if (!*stash)
	{
		*stash = (char *)malloc(1);
		if (!*stash)
			return (-1);
		(*stash)[0] = '\0';
	}
	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (-1);
	bytes = 1;
	while (!ft_strchr(*stash, '\n') && bytes > 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes < 0)
			return (free(buf), -1);
		buf[bytes] = '\0';
		*stash = ft_strjoin_free(*stash, buf);
		if (!*stash)
			return (free(buf), -1);
	}
	return (free(buf), 0);
}

static char	*extract_line(const char *stash)
{
	size_t	i;
	size_t	k;
	char	*line;

	if (!stash || stash[0] == '\0')
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = (char *)malloc(i + 1);
	if (!line)
		return (NULL);
	k = 0;
	while (k < i)
	{
		line[k] = stash[k];
		k++;
	}
	line[i] = '\0';
	return (line);
}

static char	*extract_remainder(char *stash)
{
	size_t	i;
	size_t	len;
	char	*rem;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	len = ft_strlen(stash + i);
	if (len == 0)
		return (free(stash), NULL);
	rem = (char *)malloc(len + 1);
	if (!rem)
		return (free(stash), NULL);
	rem[len] = '\0';
	while (len--)
		rem[len] = stash[i + len];
	free(stash);
	return (rem);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (fill_until_newline(fd, &stash) < 0)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	if (!stash || stash[0] == '\0')
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	line = extract_line(stash);
	stash = extract_remainder(stash);
	return (line);
}
