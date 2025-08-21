#include <unistd.h>

void	ft_putstr(char *str)
{
	if (str)
		while (*str)
			write(STDOUT_FILENO, str++, 1);
}

// int main(void)
// {
// 	ft_putstr("Welcome to 42 school!\n");
// 	return (0);
// }
