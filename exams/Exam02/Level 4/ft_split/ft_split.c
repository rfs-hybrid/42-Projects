#include <stdlib.h>

static int	ft_isspace(int c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

static int	count_words(char *str)
{
	int	n_words = 0;

	if (str)
	{
		while (*str)
		{
			while (ft_isspace(*str))
				str++;
			if (*str)
			{
				n_words++;
				while (*str && !ft_isspace(*str))
					str++;
			}
		}
	}
	return (n_words);
}

static int	word_size(char *str)
{
	int	size = 0;

	while (*str && !ft_isspace(*str))
	{
		str++;
		size++;
	}
	return (size);
}

static char	**free_split(char **split, int n)
{
	while (n--)
		free(split[n]);
	free(split);
	return (NULL);
}

char	**ft_split(char *str)
{
	int		n_words = count_words(str);
	char	**split = (char **) malloc(sizeof(char *) * (n_words + 1));

	if (!split)
		return (NULL);
	for (int i = 0; i < n_words; i++)
	{
		while (ft_isspace(*str))
			str++;
		int	len = word_size(str);
		split[i] = (char *) malloc(sizeof(char) * (len + 1));
		if (!split[i])
			return (free_split(split, i));
		for (int j = 0; j < len; j++)
			split[i][j] = *str++;
		split[i][len] = '\0';
	}
	split[n_words] = NULL;
	return (split);
}
