int	ft_strcmp(char *s1, char *s2)
{
	unsigned char	*us1 = (unsigned char *) s1;
	unsigned char	*us2 = (unsigned char *) s2;

	while (*us1 && *us1 == *us2)
	{
		us1++;
		us2++;
	}
	return (*us1 - *us2);
}

// #include <stdio.h>
// #include <string.h>

// int	main(int argc, char **argv)
// {
// 	if (argc == 3)
// 	{
// 		printf("strcmp    == %d\n", strcmp(argv[1], argv[2]));
// 		printf("ft_strcmp == %d\n", ft_strcmp(argv[1], argv[2]));
// 	}
// 	return (0);
// }
