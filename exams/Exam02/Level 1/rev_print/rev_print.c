#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		int	len = 0;
		while (argv[1][len])
			len++;
		while (len-- > 0)
			write(STDOUT_FILENO, &argv[1][len], 1);
	}
	write(STDOUT_FILENO, "\n", 1);
	return (0);
}
