#include <unistd.h>

static int	ft_isspace(int c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

static unsigned int	ft_atoi(const char *str)
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

static void	ft_putnbr_hex(unsigned int n)
{
	if (n >= 16)
		ft_putnbr_hex(n / 16);
	char	c = ((n % 16) < 10) ? (n % 16) + '0' : (n % 16) - 10 + 'a';
	write(STDOUT_FILENO, &c, 1);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		unsigned int	n = ft_atoi(argv[1]);
		ft_putnbr_hex(n);
	}
	write(STDOUT_FILENO, "\n", 1);
	return (0);
}
