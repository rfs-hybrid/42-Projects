#include <stdlib.h>

int	ft_abs(int n)
{
	return (n < 0) ? -n : n;
}

int	*ft_range(int start, int end)
{
	int	size = ft_abs(start - end) + 1;
	int	*range = (int *) malloc(sizeof(int) * size);
	if (!range)
		return (NULL);
	for (int i = 0; i <= size; i++)
		range[i] = (start < end) ? start + i : start - i;
	return (range);
}

// #include <stdio.h>

// int	main(int argc, char **argv)
// {
// 	if (argc == 3)
// 	{
// 		int	*range = ft_range(atoi(argv[1]), atoi(argv[2]));
// 		int	size = ft_abs(atoi(argv[1]) - atoi(argv[2]));
// 		for (int i = 0; i <= size; i++)
// 		{
// 			printf("%d", range[i]);
// 			if (i < size)
// 				printf(" ");
// 		}
// 		printf("\n");
// 		free(range);
// 	}
// 	return (0);
// }
