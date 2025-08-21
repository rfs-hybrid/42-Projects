#include <unistd.h>

int	ft_isspace(char c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

int	ft_toupper(int c)
{
	return ((c >= 'a' && c <= 'z') ? c - 32 : c);
}

int	ft_tolower(int c)
{
	return ((c >= 'A' && c <= 'Z') ? c + 32 : c);
}

int	main(int argc, char **argv)
{
	if (argc >= 2)
	{
		for (int i = 1; i < argc; i++)
		{
			char	*s = argv[i];
			for (int j = 0; s[j]; j++)
			{
				char	c;
				if (ft_isspace(s[j + 1]) || !s[j + 1])
					c = ft_toupper(s[j]);
				else
					c = ft_tolower(s[j]);
				write(STDOUT_FILENO, &c, 1);
			}
			write(STDOUT_FILENO, "\n", 1);
		}
	}
	else
		write(STDOUT_FILENO, "\n", 1);
	return (0);
}
