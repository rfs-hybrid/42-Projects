# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdio.h>
#include "./includes/ft_printf.h"

int	main(void)
{
	char 	*str = NULL;

	ft_printf("42 : ANDROMEDA\n");
	printf("bh : ANDROMEDA\n");

	ft_printf("42 : \"%%\"\n");
	printf("bh : \"%%\"\n");

	ft_printf("42 : %d | %i\n", 42, -42);
	printf("bh : %d | %i\n", 42, -42);

	ft_printf("42 : %u\n", 4294967295u);
	printf("bh : %u\n", 4294967295u);

	ft_printf("42 : %x\n", 3735928559u);
	printf("bh : %x\n", 3735928559u);

	ft_printf("42 : %X\n", 3735928559u);
	printf("bh : %X\n", 3735928559u);

	int x = 2011;
	ft_printf("42 : %p\n", &x);
	printf("bh : %p\n", &x);

	ft_printf("42 : %p\n", NULL);
	printf("bh : %p\n", NULL);
	
	ft_printf("42 : \"%d %d\"\n", INT_MIN, INT_MAX);
	printf("bh : \"%d %d\"\n", INT_MIN, INT_MAX);

	ft_printf("42 : %s\n", "ANDROMEDA");
	printf("bh : %s\n", "ANDROMEDA");

	ft_printf("42 : \"%s\"\n", str);
	printf("bh : \"%s\"\n", str);

	ft_printf("42 : %c %c %c\n", 'a', 'Z', '\n');
	printf("bh : %c %c %c\n", 'a', 'Z', '\n');

	ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);

	ft_printf("42 : \"%+d\"\n", 42);
	printf("bh : \"%+d\"\n", 42);

	ft_printf("42 : \"% d\"\n", 42);
	printf("bh : \"% d\"\n", 42);

	ft_printf("42 : \"%05d\"\n", 42);
	printf("bh : \"%05d\"\n", 42);

	ft_printf("42 : \"%-5d!\"\n", 42);
	printf("bh : \"%-5d!\"\n", 42);

	ft_printf("42 : \"%10s!\"\n", "andromeda");
	printf("bh : \"%10s!\"\n", "andromeda");

	ft_printf("42 : \"%.3s!\"\n", "andromeda");
	printf("bh : \"%.3s!\"\n", "andromeda");

	ft_printf("42 : \"%.5d\"\n", 42);
	printf("bh : \"%.5d\"\n", 42);

	ft_printf("42 : \"%#x %#X\"\n", 4242, 4242);
	printf("bh : \"%#x %#X\"\n", 4242, 4242);

	ft_printf("42 : \"%.0d\"\n", 0);
	printf("bh : \"%.0d\"\n", 0);

	ft_printf("42 : \"%-+10.5d\"\n", 42);
	printf("bh : \"%-+10.5d\"\n", 42);

	ft_printf("42 : \"%100d\"\n", 42);
	printf("bh : \"%100d\"\n", 42);

	x = 42;
	str = "Hello";

	ft_printf("Mix: \"%-#08x\" \"%+10.5d\" \"%20p\" \"%.4s\" \"%u\"\n", x, -123, &x, str, 123);
	printf("Mix: \"%-#8x\" \"%+10.5d\" \"%20p\" \"%.4s\" \"%u\"\n", x, -123, &x, str, 123);

	return (0);
}
