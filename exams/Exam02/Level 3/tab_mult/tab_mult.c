#include <unistd.h>

static int	ft_isspace(int c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

static unsigned int	ft_atoi(char *str)
{
	unsigned int	res = 0;

	while (ft_isspace(*str))
		str++;	
	if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
		res = res * 10 + *str++ - '0';
	return (res);
}

static void	ft_putnbr(unsigned int n)
{
	if (n >= 10)
		ft_putnbr(n / 10);
	char	c = n % 10 + '0';
	write(STDOUT_FILENO, &c, 1);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		for (unsigned int i = 1; i < 10; i++)
		{
			unsigned int	n = ft_atoi(argv[1]);
			ft_putnbr(i);
			write(STDOUT_FILENO, " x ", 3);
			ft_putnbr(n);
			write(STDOUT_FILENO, " = ", 3);
			ft_putnbr(i * n);
			write(STDOUT_FILENO, "\n", 1);
		}
	}
	else
		write(STDOUT_FILENO, "\n", 1);
	return (0);
}
