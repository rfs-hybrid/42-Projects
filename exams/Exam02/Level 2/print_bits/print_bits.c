#include <unistd.h>

void	print_bits(unsigned char octet)
{
	for (int i = 7; i >= 0; i--)
		write(STDOUT_FILENO, (octet & (1 << i)) ? "1" : "0", 1);
}

// #include <stdlib.h>

// int	main(int argc, char **argv)
// {
// 	if (argc == 2)
// 	{
// 		unsigned char c = (unsigned char)atoi(argv[1]);
// 		print_bits(c);
// 	}
// 	return (0);
// }
