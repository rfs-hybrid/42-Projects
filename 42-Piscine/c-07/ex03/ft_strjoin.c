/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 18:00:08 by maaugust          #+#    #+#             */
/*   Updated: 2025/03/10 17:00:59 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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
