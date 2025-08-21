#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc == 4 && *argv[2] && *argv[3] && !(*(argv[2] + 1) || *(argv[3] + 1)))
	{
		while (*argv[1])
		{
			if (*argv[1] == *argv[2])
				*argv[1] = *argv[3];
			write(STDOUT_FILENO, argv[1]++, 1);
		}
	}
	write(STDOUT_FILENO, "\n", 1);
	return (0);
}
