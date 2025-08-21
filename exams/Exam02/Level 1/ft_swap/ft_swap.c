void	ft_swap(int *a, int *b)
{
	int	tmp = *a;
	*a = *b;
	*b = tmp;
}

// #include <stdio.h>

// int	main(void)
// {
// 	int n1 = 21;
// 	int	n2 = 42;

// 	printf("Before: n1 = %d | n2 = %d\n", n1, n2);
// 	ft_swap(&n1, &n2);
// 	printf("After : n1 = %d | n2 = %d\n", n1, n2);
// 	return (0);
// }
