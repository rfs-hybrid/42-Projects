/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:43:12 by maaugust          #+#    #+#             */
/*   Updated: 2025/07/28 16:07:38 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

void	filter(char *s, const char *arg)
{
	void	*ptr;
	size_t	i;

	ptr = memmem(s, strlen(s), arg, strlen(arg));
	while (ptr)
	{
		i = 0;
		while (i < strlen(arg))
			s[(char *)ptr - s + i++] = '*';
		ptr = memmem(s, strlen(s), arg, strlen(arg));
	}
	write(STDOUT_FILENO, s, strlen(s));
}

int	main(int argc, char **argv)
{
	char	buffer[BUFFER_SIZE];
	char	*tmp;
	char	*line;
	ssize_t	bytes;
	size_t	len;

	if (argc != 2)
		return (EXIT_FAILURE);
	line = NULL;
	len = 0;
	bytes = read(STDIN_FILENO, buffer, BUFFER_SIZE);
	while (bytes > 0)
	{
		tmp = (char *) realloc(line, sizeof(char) * (len + bytes + 1));
		if (!tmp)
		{
			write(STDERR_FILENO, "Error: realloc\n", 15);
			return (free(line), EXIT_FAILURE);
		}
		line = tmp;
		memmove(line + len, buffer, bytes);
		len += bytes;
		line[len] = '\0';
		bytes = read(STDIN_FILENO, buffer, BUFFER_SIZE);
	}
	if (bytes < 0)
	{
		write(STDERR_FILENO, "Error: bytes\n", 13);
		return (free(line), EXIT_FAILURE);
	}
	if (!line)
		return (EXIT_FAILURE);
	filter(line, argv[1]);
	free(line);
	return (EXIT_SUCCESS);
}
