#include <unistd.h>

static int	ft_isspace(int c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

int	main(int argc, char **argv)
{
	if (argc >= 2)
	{
		while (ft_isspace(*argv[1]))
			argv[1]++;
		if (*argv[1])
		{
			char	*str = argv[1];
			while (*str && !ft_isspace(*str))
				str++;
			while (ft_isspace(*str))
				str++;
			while (*str)
			{
				while (*str && !ft_isspace(*str))
					write(STDOUT_FILENO, str++, 1);
				write(STDOUT_FILENO, " ", 1);
				while (ft_isspace(*str))
					str++;
			}
			while (ft_isspace(*argv[1]))
				argv[1]++;
			while (*argv[1] && !ft_isspace(*argv[1]))
				write(STDOUT_FILENO, argv[1]++, 1);
		}
	}
	write(STDOUT_FILENO, "\n", 1);
	return (0);
}
