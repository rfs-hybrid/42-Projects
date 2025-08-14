/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:10:47 by maaugust          #+#    #+#             */
/*   Updated: 2025/03/12 19:14:51 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_separator(char c, char *charset)
{
	int	i;

	i = -1;
	while (charset[++i])
	{
		if (c == charset[i])
			return (1);
	}
	return (0);
}

unsigned int	ft_strlen(char *str)
{
	unsigned int	len;

	len = 0;
	while (str[len++])
		;
	return (len);
}

unsigned int	count_words(char *str, char *charset)
{
	unsigned int	n_words;
	unsigned int	i;

	n_words = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && is_separator(str[i], charset))
			i++;
		if (str[i] && !is_separator(str[i], charset))
		{
			n_words++;
			while (str[i] && !is_separator(str[i], charset))
				i++;
		}
	}
	return (n_words);
}

char	*separate_string(char *str, char *charset)
{
	char			*word;
	unsigned int	i;

	i = 0;
	word = (char *) malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!word)
		return (NULL);
	while (str[i] && !is_separator(str[i], charset))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char			**split;
	unsigned int	i;
	unsigned int	j;

	split = (char **) malloc(sizeof(char *) * (count_words(str, charset) + 1));
	if (!split || !str || !charset)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] && j < count_words(str, charset))
	{
		while (str[i] && is_separator(str[i], charset))
			i++;
		if (str[i] && !is_separator(str[i], charset))
		{
			split[j++] = separate_string(&str[i], charset);
			while (str[i] && !is_separator(str[i], charset))
				i++;
		}
	}
	split[j] = 0;
	return (split);
}
