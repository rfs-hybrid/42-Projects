#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		while (*argv[1] && *argv[2])
		{
			if (*argv[1] == *argv[2])
				argv[1]++;
			argv[2]++;
		}
		write(STDOUT_FILENO, (*argv[1]) ? "0" : "1", 1);
	}
	write(STDOUT_FILENO, "\n", 1);
	return (0);
}
