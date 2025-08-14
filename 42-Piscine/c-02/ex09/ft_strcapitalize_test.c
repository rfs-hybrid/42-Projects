/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize_test.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:37:21 by maaugust          #+#    #+#             */
/*   Updated: 2025/03/01 16:31:56 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_numeric(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_is_lowercase(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int	ft_is_uppercase(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int	ft_is_alpha(char c)
{
	if (ft_is_uppercase(c) || ft_is_lowercase(c))
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	if (ft_is_lowercase(*str))
		*str -= 32;
	i = 1;
	while (str[i] != '\0')
	{
		if (!(ft_is_numeric(str[i - 1]) || ft_is_alpha(str[i - 1])))
		{
			if (ft_is_lowercase(str[i]))
				str[i] -= 32;
		}
		else if (ft_is_numeric(str[i - 1]) || ft_is_alpha(str[i - 1]))
			if (ft_is_uppercase(str[i]))
				str[i] += 32;
		i++;
	}
	return (str);
}

int	main(void)
{
	char str_in [] = "ola, tUDO bem? 42Palavras quarenta-e-duas; cinquenta+e+um";
	char *str_out;
	str_out = ft_strcapitalize(str_in);
	printf("%s\n", str_out);
}
