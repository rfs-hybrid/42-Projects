#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		while (*argv[1])
		{
			if (*argv[1] >= 'n' && *argv[1] <= 'z')
				*argv[1] = 'a' + *argv[1] - 'n';
			else if (*argv[1] >= 'N' && *argv[1] <= 'Z')
				*argv[1] = 'A' + *argv[1] - 'N';
			else if ((*argv[1] >= 'a' && *argv[1] <= 'm')
					|| (*argv[1] >= 'A' && *argv[1] <= 'M'))
				*argv[1] += 13;
			write(STDOUT_FILENO, argv[1]++, 1);
		}
	}
	write(STDOUT_FILENO, "\n", 1);
	return (0);
}
