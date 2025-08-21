int	is_power_of_2(unsigned int n)
{
	if (n == 1)
		return (1);
	unsigned int	i = 2;
	while (i < n)
		i *= 2;
	return (i == n);
}

// #include <stdio.h>
// #include <stdlib.h>

// int	main(int argc, char **argv)
// {
// 	if (argc == 2)
// 	{
// 		unsigned int	n = atoi(argv[1]);
// 		(is_power_of_2(n)) ? (printf("%u is power of 2!\n", n))
// 							: (printf("%u is NOT power of 2!\n", n));
// 	}
// 	return (0);
// }
