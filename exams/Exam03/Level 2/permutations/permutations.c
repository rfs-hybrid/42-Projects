#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

static void swap(char *a, char *b)
{
	char	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	sort_str(char *s)
{
	for (int i = 0; s[i]; i++)
		for (int j = i + 1; s[j]; j++)
			if (s[i] > s[j])
				swap(&s[i], &s[j]);
}

static bool	next_permutation(char *s, int len)
{
	int	i;
	int	j;

	for (i = len - 2; i >= 0 && s[i] >= s[i + 1]; i--);
	if (i < 0)
		return (false);
	for (j = len - 1; s[j] <= s[i]; j--);
	swap(&s[i], &s[j]);
	for (int a = i + 1, b = len - 1; a < b; a++, b--)
		swap(&s[a], &s[b]);
	return (true);
}

int	main(int argc, char **argv)
{
	int len;
	
	if (argc != 2)
		return (EXIT_FAILURE);
	for (len = 0; argv[1][len]; len++);
	sort_str(argv[1]);
	do {
		puts(argv[1]);
	} while (next_permutation(argv[1], len));
	return (EXIT_SUCCESS);
}
