int	ft_strlen(char *str)
{
	int	len;

	for (len = 0; str[len]; len++);
	return (len);
}

// #include <stdio.h>

// int main(void)
// {
// 	printf("%d\n", ft_strlen("Welcome to 42 school!"));
// 	return (0);
// }
