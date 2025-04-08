/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:54:00 by maaugust          #+#    #+#             */
/*   Updated: 2025/03/04 16:49:14 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_strlen(char *base)
{
	unsigned int	len;

	len = 0;
	while (base[len])
		len++;
	return (len);
}

unsigned int	ft_get_base_index(char c, char *base)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = ft_strlen(base);
	while (base[i] != c && i < len)
		i++;
	return (i);
}

unsigned char	is_signal(char c, unsigned char *signal)
{
	if (c == '-' || c == '+')
	{
		if (c == '-')
			*signal ^= 1;
		return (1);
	}
	return (0);
}

unsigned char	ft_is_base_valid(char *base, unsigned int len)
{
	unsigned char	i;
	unsigned char	j;

	if (len < 2 || *base == '+' || *base == '-')
		return (0);
	else if (*base == ' ' || (*base >= '\t' && *base <= '\r'))
		return (0);
	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (base[i] == base[j] || base[j] == '+' || base[j] == '-')
				return (0);
			else if (base[j] == ' ' || (base[j] >= '\t' && base[j] <= '\r'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	unsigned char	is_negative;
	unsigned int	base_len;
	int				result;
	
	is_negative = 0;
	base_len = ft_strlen(base);
	result = 0;
	if (ft_is_base_valid(base, base_len))
	{
		while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
			str++;
		while (is_signal(*str, &is_negative))
			str++;
		while (*str && (ft_get_base_index(*str, base) < base_len))
		{
			result = result * base_len + ft_get_base_index(*str, base);
			str++;
		}
	}
	if (is_negative)
		result *= -1;
	return (result);
}

int	main(int argc, char **argv)
{
	int	ret_val;

	if (argc == 3)
	{
		ret_val = ft_atoi_base(argv[1], argv[2]);	
		printf("%d\n", ret_val);
	}
	return (0);
}
