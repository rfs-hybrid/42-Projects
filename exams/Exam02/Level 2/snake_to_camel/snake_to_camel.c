#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		unsigned char	first = 1;
		for (int i = 0; argv[1][i]; i++)
		{
			while (argv[1][i] == '_')
				i++;
			if (argv[1][i])
			{
				if (i > 0 && argv[1][i - 1] == '_' && !first)
					argv[1][i] -= 32;
				if (first)
					first = 0;
				write(STDOUT_FILENO, &argv[1][i], 1);
			}
			else
				i--;
		}
	}
	write(STDOUT_FILENO, "\n", 1);
	return (0);
}
