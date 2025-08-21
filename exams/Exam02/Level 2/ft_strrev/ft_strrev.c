#include <stddef.h>

static void	swap(char *a, char *b)
{
	char	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

char	*ft_strrev(char *str)
{
	size_t	end;

	if (!str)
		return (NULL);
	for (end = 0; str[end]; end++);
	for (size_t start = 0; start < end; start++, end--)
		swap(&str[start], &str[end - 1]);
	return (str);
}

// #include <stdio.h>
// #include <string.h>

// int	main(int argc, char **argv)
// {
// 	if (argc == 2)
// 	{
// 		printf("strrev    == %s\n", strrev(argv[1]));	// It's possible this function won't be recognized depending on the compiler
// 		printf("ft_strrev == %s\n", ft_strrev(argv[1]));
// 	}
// 	return (0);
// }
