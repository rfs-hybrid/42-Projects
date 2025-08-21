#include <stdio.h>

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char c = 0;
	for (int i = 0; i < 8; i++)
		c |= ((octet & (1 << i)) ? 1 : 0) << (7 - i);
	return (c);
}

// #include <unistd.h>
// #include <stdlib.h>

// static void	print_bits(unsigned char octet)
// {
// 	for (int i = 7; i >= 0; i--)
// 		write(STDOUT_FILENO, (octet & (1 << i)) ? "1" : "0", 1);
// }

// int	main(int argc, char **argv)
// {
// 	if (argc == 2)
// 		print_bits(reverse_bits(atoi(argv[1])));
// 	return (0);
// }
