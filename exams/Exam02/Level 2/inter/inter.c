#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		for (int i = 0; argv[1][i]; i++)
		{
			int	is_dup = 0;
			for (int j = 0; j < i; j++)
				if (argv[1][i] == argv[1][j])
				{
					is_dup = 1;
					break ;
				}
			if (!is_dup)
				for (int j = 0; argv[2][j]; j++)
					if (argv[1][i] == argv[2][j])
					{
						write(STDOUT_FILENO, &argv[1][i], 1);
						break ;
					}
		}
	}
	write (STDOUT_FILENO, "\n", 1);
	return (0);
}
