#include <unistd.h>

static int	ft_isspace(int c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

static int	ft_atoi(const char *str)
{
	int	res = 0;
	int	sign = 1;

	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign *= -1;
	while (*str >= '0' && *str <= '9')
		res = res * 10 + *str++ - '0';
	return (res * sign);
}

static void	ft_putnbr(int n)
{
	char	c;

	if (n >= 10)
		ft_putnbr(n / 10);
	c = n % 10 + '0';
	write(STDOUT_FILENO, &c, 1);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		int	n = ft_atoi(argv[1]);
		int	res = 0;
		for (int i = 2; i <= n; i++)
			for (int j = 2; j <= i; j++)
				if (i == j)
					res += i;
				else if (i % j == 0)
					break ;
		ft_putnbr(res);
	}
	write(STDOUT_FILENO, "\n", 1);
	return (0);
}
