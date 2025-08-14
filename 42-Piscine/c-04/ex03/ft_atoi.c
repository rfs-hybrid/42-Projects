/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:27:45 by maaugust          #+#    #+#             */
/*   Updated: 2025/03/03 20:01:05 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char	is_whitespace(char c)
{
	return (c == ' ' || ((c >= '\t' && c <= '\r')));
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

unsigned char	is_numeric(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(char *str)
{
	unsigned char	is_negative;
	int				result;

	is_negative = 0;
	result = 0;
	while (is_whitespace(*str))
		str++;
	while (is_signal(*str, &is_negative))
		str++;
	while (*str && is_numeric(*str))
	{
		result = result * 10 + *str - '0';
		str++;
	}
	if (is_negative)
		result *= -1;
	return (result);
}
