static unsigned int	hcf(unsigned int a, unsigned int b)
{
	while (b)
	{
		unsigned int	tmp = b;
		b = a % b;
		a = tmp;
	}
	return (a);
}

unsigned int	lcm(unsigned int a, unsigned int b)
{
	if (!a || !b )
		return (0);
	return ((a / hcf(a, b)) * b);
}

// #include <stdio.h>
// #include <stdlib.h>

// int	main(int argc, char **argv)
// {
// 	if (argc == 3)
// 		printf("lcm(%d, %d) == %d\n", atoi(argv[1]), atoi(argv[2]), lcm(atoi(argv[1]), atoi(argv[2])));
// 	return (0);
// }
