/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:39:15 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/23 15:05:41 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_str_realloc(char **str, size_t size)
{
	char	*new;
	size_t	len;

	if (!str || !*str)
	{
		new = (char *) malloc(sizeof(char) * (size + 1));
		if (!new)
			return (free(*str), NULL);
		*new = '\0';
	}
	else
	{
		len = ft_strlen(*str);
		new = (char *) malloc(sizeof(char) * (len + size + 1));
		if (!new)
			return (free(*str), NULL);
		ft_strlcpy(new, *str, len + 1);
		free(*str);
		str = NULL;
	}
	return (new);
}

static ssize_t	read_line(int fd, char *buffer, char **new_line)
{
	ssize_t	n_bytes;

	if (fd < 0 || fd >= FD_SIZE || BUFFER_SIZE <= 0)
		return (0);
	if (!*buffer)
	{
		n_bytes = read(fd, buffer, BUFFER_SIZE);
		if (n_bytes < 0 && *new_line)
		{
			free (*new_line);
			*new_line = NULL;
		}
	}
	else
	{
		n_bytes = 0;
		while (*buffer++)
			n_bytes++;
	}
	return (n_bytes);
}

char	*get_next_line(int fd)
{
	static char	buffer[FD_SIZE][BUFFER_SIZE];
	char		*new_line;
	ssize_t		n_bytes;
	size_t		len;
	int			i;

	new_line = NULL;
	n_bytes = read_line(fd, buffer[fd], &new_line);
	while (n_bytes > 0)
	{
		i = 0;
		while (i < n_bytes && buffer[fd][i] && buffer[fd][i++] != '\n')
			;
		new_line = ft_str_realloc(&new_line, i);
		if (!new_line)
			break ;
		len = ft_strlen(new_line);
		ft_strlcpy(new_line + len, buffer[fd], i + 1);
		ft_strlcpy(buffer[fd], buffer[fd] + i, n_bytes - i + 1);
		len += i;
		if (new_line[len - 1] == '\n')
			break ;
		n_bytes = read_line(fd, buffer[fd], &new_line);
	}
	return (new_line);
}
