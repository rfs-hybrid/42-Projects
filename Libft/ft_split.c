/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:33:49 by maaugust          #+#    #+#             */
/*   Updated: 2025/04/14 18:24:07 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *s, char c)
{
	size_t	n_words;
	size_t	i;

	n_words = 0;
	i = 0;
	while (*(s + i))
	{
		while (*(s + i) && *(s + i) == c)
			i++;
		if (*(s + i) && *(s + i) != c)
		{
			n_words++;
			while (*(s + i) && *(s + i) != c)
				i++;
		}
	}
	return (n_words);
}

static char	*add_string(const char *s, char c)
{
	char	*word;
	size_t	len;
	size_t	i;

	len = 0;
	while (*(s + len) && *(s + len) != c)
		len++;
	word = (char *) ft_calloc(len + 1, sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (*(s + i) && *(s + i) != c)
	{
		*(word + i) = *(s + i);
		i++;
	}
	return (word);
}

static char	**free_memory(char **split, size_t n)
{
	while (n-- > 0)
		free(split[n]);
	free(split);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	split = (char **)ft_calloc(count_words(s, c) + 1, sizeof(char *));
	if (!split)
		return (NULL);
	i = 0;
	j = 0;
	while (j < count_words(s, c))
	{
		while (*(s + i) == c && *(s + i + 1))
			i++;
		*(split + j) = add_string(s + i, c);
		if (!(*(split + j)))
			return (free_memory(split, j));
		j++;
		while (*(s + i) && *(s + i) != c)
			i++;
	}
	return (split);
}
