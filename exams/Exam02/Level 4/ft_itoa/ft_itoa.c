#include <stdlib.h>

static int	get_nbr_size(long nbr)
{
	int size = 1;

	if(nbr < 0)
		size++;
	while (nbr /= 10)
		size++;
	return (size);
}

static void	int_to_ascii(char *str, long nbr, int size)
{
	str[size] = '\0';
	if (nbr < 0)
	{
		*str++ = '-';
		nbr *= -1;
		size--;
	}
	while(size-- > 0)
	{
		str[size] = nbr % 10 + '0';
		nbr /= 10;
	}
}

char    *ft_itoa(int nbr)
{
	int		size = get_nbr_size((long)nbr);
	char	*str = (char *) malloc(sizeof(char) * (size + 1));

	if (!str)
		return (NULL);
	int_to_ascii(str, (long)nbr, size);
	return (str);
}

// #include <stdio.h>

// int	main(int argc, char **argv)
// {
// 	if (argc == 2)
// 	{
// 		char	*str = ft_itoa(atoi(argv[1]));
// 		printf("%s", str);
// 		free(str);
// 	}
// 	printf("\n");
// 	return (0);
// }
