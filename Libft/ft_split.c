/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:33:49 by maaugust          #+#    #+#             */
/*   Updated: 2025/04/11 15:12:40 by maaugust         ###   ########.fr       */
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

static size_t	word_length(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (*(s + len) && *(s + len) != c)
		len++;
	return (len);
}

static char	*separate_string(const char *s, char c)
{
	char	*word;
	size_t	i;

	i = 0;
	word = (char *) ft_calloc(word_length(s, c) + 1, sizeof(char));
	if (!word)
		return (NULL);
	while (*(s + i) && *(s + i) != c)
	{
		*(word + i) = *(s + i);
		i++;
	}
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	n_words;
	size_t	i;
	size_t	j;

	n_words = count_words(s, c);
	split = (char **)ft_calloc(n_words + 1, sizeof(char *));
	if (!split || !s)
		return (NULL);
	i = 0;
	j = 0;
	while (*(s + i) && j < n_words)
	{
		while (*(s + i) && *(s + i) == c)
			i++;
		if (*(s + i) && *(s + i) != c)
		{
			*(split + j++) = separate_string(s + i, c);
			while (*(s + i) && *(s + i) != c)
				i++;
		}
	}
	return (split);
}
