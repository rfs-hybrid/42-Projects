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
			int i = 1;
			if (ft_isupper(*argv[1]))
				i = *argv[1] - 'A' + 1;
			else if (ft_islower(*argv[1]))
				i = *argv[1] - 'a' + 1;
			while (i--)
				write(STDOUT_FILENO, argv[1], 1);
			argv[1]++;
		}
	}
	write(STDOUT_FILENO, "\n", 1);
	return (0);
}
