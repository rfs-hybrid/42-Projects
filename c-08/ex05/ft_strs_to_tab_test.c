/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 22:40:27 by maaugust          #+#    #+#             */
/*   Updated: 2025/03/10 12:20:22 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdio.h>
#include <stdlib.h>

void	ft_show_tab(struct s_stock_str *par);

unsigned int	ft_strlen(char *str)
{
	unsigned int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strdup(char *src)
{
	char			*dup;
	unsigned int	src_len;
	unsigned int	i;

	src_len = ft_strlen(src);
	dup = (char *) malloc (sizeof(char) * (src_len + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < src_len)
	{
		dup[i] = src[i];
		i++;
	}
	dup[src_len] = '\0';
	return (dup);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str		*arr;
	int				i;

	arr = (t_stock_str *) malloc(sizeof(t_stock_str) * (ac + 1));
	if (!arr)
		return (NULL);
	i = -1;
	while (++i < ac)
	{
		if (!av[i])
			return (NULL);
		arr[i].size = ft_strlen(av[i]);
		arr[i].str = ft_strdup(av[i]);
		arr[i].copy = ft_strdup(arr[i].str);
		if (!(arr[i].str) || !(arr[i].copy))
			return (NULL);
	}
	arr[i].str = 0;
	return (arr);
}

int	main(int argc, char **argv)
{
	t_stock_str *result;
	int	i;
	
	result = ft_strs_to_tab(argc - 1, argv + 1);
	i = -1;
	while (++i < argc - 1)
	{
		printf("size[%d] = %d\n", i, result[i].size);
		printf("str [%d] = %s\n", i, result[i].str);
		printf("copy[%d] = %s\n", i, result[i].copy);
	}
	printf("-------------------------------------------\n");
	ft_show_tab(result);
	if (result)
		free(result);
}
