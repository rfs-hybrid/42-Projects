/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 18:00:08 by maaugust          #+#    #+#             */
/*   Updated: 2025/03/10 19:01:28 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int	ft_strlen(char *str)
{
	unsigned int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

unsigned int	ft_total_strlen(int size, char **strs, char *sep)
{
	unsigned int	len;
	int				i;

	len = 0;
	i = -1;
	while (++i < size)
	{
		len += ft_strlen(strs[i]);
		if (i < size - 1)
			len += ft_strlen(sep);
	}
	return (len);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (dest[++i])
		;
	while (src[++j])
		dest[i + j] = src[j];
	dest[i + j] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char			*ret_str;
	unsigned int	total_len;
	int				i;

	total_len = 0;
	if (size > 0)
		total_len = ft_total_strlen(size, strs, sep);
	ret_str = (char *)malloc(sizeof(char) * (total_len + 1));
	if (!ret_str)
		return (NULL);
	ret_str[0] = '\0';
	if (size > 0)
	{
		i = -1;
		while (++i < size)
		{
			(void) ft_strcat(ret_str, strs[i]);
			if (i < size - 1)
				(void) ft_strcat(ret_str, sep);
		}
		ret_str[(sizeof(char) * (total_len + 1)) - 1] = '\0';
	}
	return (ret_str);
}

int	main(void)
{
	char **string_array = (char **) malloc(sizeof(char*) * 7);
	char str0[] = "Hello";
	char str1[] = "am";
	char str2[] = "here";
	char str3[] = "to";
	char str4[] = "blow";
	char str5[] = "up";
	char str6[] = "moulinette";

	string_array[0] = str0;
	string_array[1] = str1;
	string_array[2] = str2;
	string_array[3] = str3;
	string_array[4] = str4;
	string_array[5] = str5;
	string_array[6] = str6;

	char *result = ft_strjoin(1, string_array, "...");
	printf("%s\n", result);
	free(string_array);
	free(result);
	return (0);
}
