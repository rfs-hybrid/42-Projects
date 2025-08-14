#define _GNU_SOURCE
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

static void	filter(char *str, const char *sub)
{
	void	*ptr = memmem(str, strlen(str), sub, strlen(sub));

	while (ptr)
	{
		for (size_t i = 0; i < strlen(sub); i++)
			str[(char *) ptr - str + i] = '*';
		ptr = memmem(str, strlen(str), sub, strlen(sub));
	}
	write(STDOUT_FILENO, str, strlen(str));
}

int	main(int argc, char **argv)
{
	char	buffer[BUFFER_SIZE];
	char	*line;
	char	*tmp;
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
	return (free(line), EXIT_SUCCESS);
}
