#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*dup;
	size_t	len;

	if (!src)
		return (NULL);
	for (len = 0; src[len]; len++);
	dup = (char *) malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	for (size_t i = 0; i < len; i++)
		dup[i] = src[i];
	dup[len] = '\0';
	return (dup);
}

// #include <stdio.h>
// #include <string.h>

// int	main(int argc, char **argv)
// {
// 	if (argc == 2)
// 	{
// 		char	*dup = strdup(argv[1]);
// 		char	*dup2 = ft_strdup(argv[1]);
// 		printf("strdup    == %s\n", dup);
// 		printf("ft_strdup == %s\n", dup2);
// 		free(dup);
// 		free(dup2);
// 	}
// 	return (0);
// }
