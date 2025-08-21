#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		while (*argv[1])
		{
			if (*argv[1] == 'z')
				*argv[1] = 'a';
			else if (*argv[1] == 'Z')
				*argv[1] = 'A';
			else if ((*argv[1] >= 'a' && *argv[1] <= 'y')
					|| (*argv[1] >= 'A' && *argv[1] <= 'Y'))
				*argv[1] += 1;
			write(STDOUT_FILENO, argv[1]++, 1);
		}
	}
	write(STDOUT_FILENO, "\n", 1);
	return (0);
}
