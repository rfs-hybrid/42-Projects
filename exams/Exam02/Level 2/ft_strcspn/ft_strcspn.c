#include <stddef.h>

static char	*ft_strchr(const char *s, int c)
{
	do {
		if (*s == (char) c)
			return ((char *)s);
	} while (*s++);
	return (NULL);
}

size_t	ft_strcspn(const char *s, const char *reject)
{
	char	*str = ft_strchr(s, '\0');
	size_t	n = (size_t)(str - s);

	while (*reject)
	{
		str = ft_strchr(s, *reject++);
		if (str && (size_t)(str - s) < n)
			n = (size_t)(str - s);
	}
	return (n);
}

// #include <stdio.h>
// #include <string.h>

// int	main(int argc, char **argv)
// {
// 	if (argc == 3)
// 	{
// 		printf("strcspn    == %lu\n", strcspn(argv[1], argv[2]));
// 		printf("ft_strcspn == %lu\n", ft_strcspn(argv[1], argv[2]));
// 	}
// 	return (0);
// }
