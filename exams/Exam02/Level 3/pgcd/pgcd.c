#include <stdio.h>
#include <stdlib.h>

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

int	main(int argc, char **argv)
{
	if (argc == 3 && atoi(argv[1]) > 0 && atoi(argv[2]) > 0)
	{
		printf("%d", hcf(atoi(argv[1]), atoi(argv[2])));
	}
	printf("\n");
	return (0);
}
