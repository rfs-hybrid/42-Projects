#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 1024

static void	rip(const char *input, char *current, int len,
				int pos, int bal, int rem_open, int rem_close)
{
	if (bal < 0 || rem_open < 0 || rem_close < 0)
		return ;
	if (pos == len)
	{
		current[pos] = '\0';
		if (bal == 0 && rem_open == 0 && rem_close == 0)
			puts(current);
		return;
	}
	if (input[pos] == '(')
	{
		if (rem_open > 0)
		{
			current[pos] = ' ';
			rip(input, current, len, pos + 1, bal, rem_open - 1, rem_close);
		}
		current[pos] = input[pos];
		rip(input, current, len, pos + 1, bal + 1, rem_open, rem_close);
	}
	else if (input[pos] == ')')
	{
		if (rem_close > 0)
		{
			current[pos] = ' ';
			rip(input, current, len, pos + 1, bal, rem_open, rem_close - 1);
		}
		if (bal > 0)
		{
			current[pos] = input[pos];
			rip(input, current, len, pos + 1, bal - 1, rem_open, rem_close);
		}
	}
	else
	{
		current[pos] = input[pos];
		rip(input, current, len, pos + 1, bal, rem_open, rem_close);
	}
}

static void	rem_count(char *input, int *rem_open, int *rem_close)
{
	while (*input)
	{
		if (*input == '(')
			(*rem_open)++;
		else if (*input == ')')
		{
			if (*rem_open == 0)
				(*rem_close)++;
			else
				(*rem_open)--;
		}
		input++;
	}
}

int	main(int argc, char **argv)
{
	char	*input;
	char 	current[MAX_LEN + 1];
	int		len;
	int		rem_open;
	int		rem_close;

	if (argc != 2)
		return (EXIT_FAILURE);
	input = argv[1];
	for (len = 0; input[len]; len++);
	if (len > MAX_LEN)
		return (EXIT_FAILURE);
	rem_open = 0;
	rem_close = 0;
	rem_count(input, &rem_open, &rem_close);
	rip(input, current, len, 0, 0, rem_open, rem_close);
	return (EXIT_SUCCESS);
}
