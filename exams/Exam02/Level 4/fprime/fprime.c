#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		unsigned int	n = atoi(argv[1]);
		if (n < 2)
			printf("%d", n);
		else
		{
			unsigned int	i = 2;
			while (i <= n)
			{
				if (n % i == 0)
				{
					printf("%d", i);
					if (i != n)
						printf("*");
					n /= i;
				}
				else
					i++;
			}
		}
	}
	printf("\n");
	return (0);
}
