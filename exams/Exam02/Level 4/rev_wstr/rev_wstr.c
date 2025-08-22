#include <unistd.h>

static int	ft_isspace(int c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		char	*str = argv[1];
		int		start = 0;
		int 	end = 0;
		int		first_word = 1;

		while (argv[1][end])
			end++;
		for (int i = end - 1; i >= 0;)
		{
			while (i >= 0 && ft_isspace(str[i]))
				i--;
			if (i < 0)
				break ;
			end = i;
			while (i >= 0 && !ft_isspace(str[i]))
				i--;
			start = i + 1;
			if (!first_word)
				write(STDOUT_FILENO, " ", 1);
			while (start <= end)
				write(STDOUT_FILENO, &str[start++], 1);
			if (first_word)
				first_word = 0;
		}
	}
	write(STDOUT_FILENO, "\n", 1);
	return (0);
}
