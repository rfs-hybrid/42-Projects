/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 21:40:17 by maaugust          #+#    #+#             */
/*   Updated: 2025/05/08 18:11:14 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static size_t	get_line_len(char *str)
{
	size_t	len;

	len = 0;
	while (*str && *str++ != '\n')
		len++;
	return (len);
}

static char	*update_stash(char *str)
{
	char	*sub;
	size_t	len;

	len = get_line_len(str);
	if (!str[len])
		return (NULL);
	sub = ft_substr(str, len + 1, ft_strlen(str) - len);
	if (!sub)
		return (NULL);
	if (!*sub)
	{
		free(sub);
		return (NULL);
	}
	*(str + len + 1) = '\0';
	return (sub);
}

static char	*read_line(int fd, char *str_stash, char *buffer)
{
	char	*tmp;
	ssize_t	n_bytes;

	n_bytes = 1;
	while (n_bytes > 0)
	{
		n_bytes = read(fd, buffer, BUFFER_SIZE);
		if (n_bytes <= 0)
		{
			if (n_bytes == 0)
				break ;
			free(str_stash);
			return (NULL);
		}
		buffer[n_bytes] = '\0';
		if (!str_stash)
			str_stash = ft_strdup("");
		tmp = str_stash;
		str_stash = ft_strjoin(tmp, buffer);
		free(tmp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (str_stash);
}

char	*get_next_line(int fd)
{
	static char	*str_stash = NULL;
	char		*buffer;
	char		*next_line;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buffer, 0) < 0)
	{
		free(buffer);
		free(str_stash);
		str_stash = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	next_line = read_line(fd, str_stash, buffer);
	free(buffer);
	if (!next_line)
		return (NULL);
	str_stash = update_stash(next_line);
	return (next_line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*next_line;

// 	fd = open("test.txt", O_RDONLY);
// 	if (fd < 0)
// 			return (-1);
// 	next_line = get_next_line(fd);
// 	while (next_line)
// 	{
// 		printf("%s", next_line);
// 		free(next_line);
// 		next_line = get_next_line(fd);
// 	}
// 	printf("%s", next_line);
// 	return (0);
// }
