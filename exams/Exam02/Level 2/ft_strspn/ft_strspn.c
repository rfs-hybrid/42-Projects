#include <stddef.h>

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t	n = 0;
	size_t	i;

	if (s && accept)
	{
		while (*s)
		{
			for (i = 0; accept[i]; i++)
				if (*s == accept[i])
					break ;
			if (!accept[i])
				break ;
			n++;
			s++;
		}
	}
	return (n);
}

// #include <stdio.h>
// #include <string.h>

// int	main(int argc, char **argv)
// {
// 	if (argc == 3)
// 	{
// 		printf("strspn    == %lu\n", strspn(argv[1], argv[2]));
// 		printf("ft_strspn == %lu\n", ft_strspn(argv[1], argv[2]));
// 	}
// 	return (0);
// }
