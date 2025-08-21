#include <unistd.h>

static void	putnbr(int n)
{
	if (n >= 10)
		putnbr(n / 10);
	char	c = n % 10 + '0';
	write(STDOUT_FILENO, &c, 1);
}

int	main(int argc, char **argv)
{
	(void)argv;
	putnbr(argc - 1);
	write(STDOUT_FILENO, "\n", 1);
	return (0);
}
