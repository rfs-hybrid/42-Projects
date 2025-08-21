#include <unistd.h>

static int	ft_isspace(char c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		size_t	len = 0;
		while (argv[1][len])
			len++;
		while (len > 0 && ft_isspace(argv[1][len - 1]))
			len--;
		while (len > 0 && !ft_isspace(argv[1][len - 1]))
			len--;
		while (argv[1][len] && !ft_isspace(argv[1][len]))
			write(STDOUT_FILENO, &argv[1][len++], 1);
	}
	write(STDOUT_FILENO, "\n", 1);
	return (0);
}
