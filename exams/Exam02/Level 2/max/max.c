int		max(int* tab, unsigned int len)
{
	if (!tab || !len)
		return (0);
	int	val = tab[0];
	for (unsigned int i = 1; i < len; i++)
		if (val < tab[i])
			val = tab[i];
	return (val);
}

// #include <stdio.h>
// #include <stdlib.h>

// int	main(int argc, char **argv)
// {
// 	int val;
// 	if (argc >= 2)
// 	{
// 		unsigned int	len = argc - 1;
// 		int	*tab = (int *)calloc(len, sizeof(int));
// 		if (!tab)
// 			val = max(tab, len);
// 		else
// 		{
// 			for (unsigned int i = 0; i < len; i++)
// 				tab[i] = atoi(argv[1 + i]);
// 			val = max(tab, len);
// 			free(tab);
// 		}
// 		printf("Max == %d\n", val);
// 	}
// 	else
// 	{
// 		int tab[5] = {-9, 2, 21, -43, 10};
// 		val = max(tab, 0);
// 		printf("Max == %d\n", val);
// 	}
// 	return (0);
// }
