#include <unistd.h>

static void	putnbr(int n)
{
	char	c;

	if (n > 10)
		putnbr(n / 10);
	c = n % 10 + '0';
	write(STDOUT_FILENO, &c, 1);
}

int	main(void)
{
	for (int n = 1; n <= 100; n++)
	{
		if (n % 3 == 0)
			write(STDOUT_FILENO, "fizz", 4);
		if (n % 5 == 0)
			write(STDOUT_FILENO, "buzz", 4);
		if (!(n % 3 == 0 || n % 5 == 0))
			putnbr(n);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}
