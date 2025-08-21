#include <stddef.h>

char	*ft_strpbrk(const char *s1, const char *s2)
{
	if (!s1 || !s2)
		return (NULL);
	while (*s1)
	{
		for (size_t i = 0; s2[i]; i++)
			if (*s1 == s2[i])
				return ((char *)s1);
		s1++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>

// int	main(int argc, char **argv)
// {
// 	if (argc == 3)
// 	{
// 		printf("strpbrk    == %s\n", strpbrk(argv[1], argv[2]));
// 		printf("ft_strpbrk == %s\n", ft_strpbrk(argv[1], argv[2]));
// 	}
// 	return (0);
// }
