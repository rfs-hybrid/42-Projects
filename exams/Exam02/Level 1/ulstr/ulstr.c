#include <unistd.h>

static int	ft_isupper(int c)
{
	return (c >= 'A' && c <= 'Z');
}

static int	ft_islower(int c)
{
	return (c >= 'a' && c <= 'z');
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		while (*argv[1])
		{
			if (ft_isupper(*argv[1]))
				*argv[1] += 32;
			else if (ft_islower(*argv[1]))
				*argv[1] -= 32;
			write(STDOUT_FILENO, argv[1]++, 1);
		}
	}
	write(STDOUT_FILENO, "\n", 1);
	return (0);
}
