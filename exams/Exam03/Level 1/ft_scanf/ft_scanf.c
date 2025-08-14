#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>

int	match_space(FILE *f)
{
	int	c;

	while (1)
	{
		c = fgetc(f);
		if (c == EOF)
			return (EOF);
		if (!isspace(c))
		{
			ungetc(c, f);
			break ;
		}
	}
	return (0);
}

int	match_char(FILE *f, char c)
{
	int	ch = fgetc(f);

	if ((char) ch == c)
		return (1);
	if (ch != EOF)
		ungetc(ch, f);
	return (0);
}

int	scan_char(FILE *f, va_list ap)
{
	int	c = fgetc(f);

	if (c == EOF)
		return (0);
	char	*cp = va_arg(ap, char *);
	*cp = (char) c;
	return (1);
}

int	scan_int(FILE *f, va_list ap)
{
	int	res = 0;
	int	sign = 1;
	int	c = fgetc(f);

	if (c == '-' || c == '+')
	{
		if (c == '-')
			sign *= -1;
		c = fgetc(f);
	}
	while (c >= '0' && c <= '9')
	{
		res = res * 10 + c - '0';
		c = fgetc(f);
	}
	int	*ip = va_arg(ap, int *);
	*ip = res * sign;
	return (1);
}

int	scan_string(FILE *f, va_list ap)
{
	int	c = fgetc(f);
	
	if (c == EOF)
		return (0);
	int	i = 0;
	char	*sp = va_arg(ap, char *);
	while (c != EOF && !isspace(c))
	{
		sp[i++] = (char) c;
		c = fgetc(f);
	}
	if (c != EOF)
		ungetc(c, f);
	sp[i] = '\0';
	return (1);
}

int	match_conv(FILE *f, const char **format, va_list ap)
{
	switch (**format)
	{
		case 'c':
			return scan_char(f, ap);
		case 'd':
			match_space(f);
			return scan_int(f, ap);
		case 's':
			match_space(f);
			return scan_string(f, ap);
		case EOF:
			return -1;
		default:
			return -1;
	}
}

int	ft_vfscanf(FILE *f, const char *format, va_list ap)
{
	int	nconv = 0;

	int	c = fgetc(f);
	if (c == EOF)
		return EOF;
	ungetc(c, f);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (match_conv(f, &format, ap) != 1)
				break;
			else
				nconv++;
		}
		else if (isspace(*format))
		{
			if (match_space(f) == -1)
				break;
		}
		else if (match_char(f, *format) != 1)
			break;
		format++;
	}
	
	if (ferror(f))
		return EOF;
	return nconv;
}

int	ft_scanf(const char *format, ...)
{
	va_list	ap;

	va_start(ap, format);
	int ret = ft_vfscanf(stdin, format, ap);
	va_end(ap);
	return ret;
}

// int	main(void)
// {
// 	char str[100];
// 	int num;
// 	char ch;
// 	int ret;

// 	printf("=== Testing %%s %%d %%c ===\n");

// 	printf("Enter a word, a number, and a character: ");
// 	ret = ft_scanf("%s %d %c", str, &num, &ch);

// 	printf("\nft_scanf returned: %d\n", ret);
// 	printf("String read: \"%s\"\n", str);
// 	printf("Integer read: %d\n", num);
// 	printf("Character read: '%c'\n", ch);

// 	printf("\n--- Now with real scanf for comparison ---\n");

// 	printf("Enter a word, a number, and a character: ");
// 	ret = scanf("%s %d %c", str, &num, &ch);

// 	printf("\nscanf returned: %d\n", ret);
// 	printf("String read: \"%s\"\n", str);
// 	printf("Integer read: %d\n", num);
// 	printf("Character read: '%c'\n", ch);

// 	return (0);
// }
