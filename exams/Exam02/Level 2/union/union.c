#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		char	un[256];
		int		len = 0;
		while (*argv[1])
		{
			unsigned char	is_dup = 0;
			for (int i = 0; i < len; i++)
				if (*argv[1] == un[i])
				{
					is_dup = 1;
					break ;
				}
			if (!is_dup)
			{
				un[len] = *argv[1];
				len++;
			}
			argv[1]++;
		}
		while (*argv[2])
		{
			unsigned char	is_dup = 0;
			for (int i = 0; i < len; i++)
				if (*argv[2] == un[i])
				{
					is_dup = 1;
					break ;
				}
			if (!is_dup)
			{
				un[len] = *argv[2];
				len++;
			}
			argv[2]++;
		}
		for (int i = 0; i < len; i++)
			write(STDOUT_FILENO, &un[i], 1);
	}
	write(STDOUT_FILENO, "\n", 1);
	return (0);
}
