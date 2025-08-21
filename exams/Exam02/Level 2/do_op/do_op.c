#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	if (argc == 4)
	{
		int	a = atoi(argv[1]);
		int	b = atoi(argv[3]);
		if (*argv[2] == '+')
			printf("%d", a + b);
		if (*argv[2] == '-')
			printf("%d", a - b);
		if (*argv[2] == '*')
			printf("%d", a * b);
		if (*argv[2] == '/')
			printf("%d", a / b);
		if (*argv[2] == '%')
			printf("%d", a % b);
	}
	printf("\n");
	return (0);
}
