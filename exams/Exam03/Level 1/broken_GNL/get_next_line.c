#include "get_next_line.h"

static size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

static size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size > 0)
	{
		i = 0;
		while (i < size - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

static char	*ft_realloc_str(char **s, size_t size)
{
	char	*new;
	size_t	len;

	if (!s || !*s)
	{
		new = (char *) malloc(sizeof(char) * (size + 1));
		if (!new)
			return (NULL);
		*new = '\0';
		return (new);
	}
	len = ft_strlen(*s);
	new = (char *) malloc(sizeof(char) * (len + size + 1));
	if (!new)
		return (free(*s), NULL);
	ft_strlcpy(new, *s, len + 1);
	return (free(*s), new);
}

static ssize_t	ft_read(int fd, char *buffer, char **line)
{
	ssize_t	bytes;

	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (0);
	if (!*buffer)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0 && *line)
		{
			free(*line);
			*line = NULL;
		}
		return (bytes);
	}
	bytes = 0;
	while (*buffer++)
		bytes++;
	return (bytes);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*line;
	ssize_t		bytes;
	ssize_t		i;
	size_t		len;

	line = NULL;
	bytes = ft_read(fd, buffer, &line);
	while (bytes > 0)
	{
		i = 0;
		while (i < bytes && buffer[i] && buffer[i++] != '\n')
			;
		line = ft_realloc_str(&line, i);
		if (!line)
			break ;
		len = ft_strlen(line);
		ft_strlcpy(line + len, buffer, i + 1);
		ft_strlcpy(buffer, buffer + i, bytes - i + 1);
		if (line[len + i - 1] == '\n')
			break ;
		bytes = ft_read(fd, buffer, &line);
	}
	return (line);
}

// #include <sys/stat.h>
// #include <fcntl.h>
// #include <stdio.h>

// int	main(int argc, char **argv)
// {
// 	if (argc != 3)
// 		return (EXIT_FAILURE);
// 	int		fd = open(argv[1], O_RDONLY);
// 	int		n = atoi(argv[2]);
// 	char	*line = NULL;
// 	while (n-- > 0)
// 	{
// 		line = get_next_line(fd);
// 		printf("%s", line);
// 		free(line);
// 	}
// 	close(fd);
// 	return (EXIT_SUCCESS);
// }
