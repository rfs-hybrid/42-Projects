#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		const char *s1 = argv[1];
		const char *s2 = argv[2];
		while (*s1 && *s2)
		{
			if (*s1 == *s2)
				s1++;
			s2++;
		}
		if (!*s1)
			while (*argv[1])
				write(STDOUT_FILENO, argv[1]++, 1);
	}
	write(STDOUT_FILENO, "\n", 1);
	return (0);
}
