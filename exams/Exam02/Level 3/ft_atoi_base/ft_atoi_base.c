static int	ft_isspace(int c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

static int	from_hex_to_int(int c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'A' && c <= 'F')
		return (10 + c - 'A');
	else if (c >= 'a' && c <= 'f')
		return (10 + c - 'a');
	else
		return (-1);
}

int	ft_atoi_base(const char *str, int str_base)
{
	if (str_base > 16 || str_base < 2)
		return (0);
	int res	= 0;
	int	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign *= -1;
	while (1)
	{
		int val = from_hex_to_int(*str++);
		if (val < 0 || val >= str_base)
			break ;
		res = res * str_base + val;
	}
	return (res * sign);
}

// #include <stdio.h>
// #include <stdlib.h>

// int	main(int argc, char **argv)
// {
// 	if (argc == 3)
// 		printf("%d", ft_atoi_base(argv[1], atoi(argv[2])));
// 	return (0);
// }
