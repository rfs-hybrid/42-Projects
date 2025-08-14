/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 19:07:04 by maaugust          #+#    #+#             */
/*   Updated: 2025/02/24 09:52:29 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_update_last_digits(char *array, int len, int offset)
{
	array[(len - 1) - offset]++;
	while (offset > 0)
	{
		array[len - offset] = array[(len - 1) - offset] + 1;
		offset--;
	}
}

void	ft_increment_digits(char *array, int len)
{
	int	pos;

	pos = 0;
	while (array[len - 1] <= '9')
	{
		write (1, array, len);
		if (array[0] != ('9' - (len - 1)))
			write (1, ", ", 2);
		array[len - 1]++;
	}
	array[len - 1]--;
	if (array[0] != ('9' - (len - 1)))
	{
		while (array[(len - 1) - pos] == '9' - pos)
			pos++;
		ft_update_last_digits(array, len, pos);
		ft_increment_digits(array, len);
	}
}

void	ft_initialize_digits(char *array, int len)
{
	int	pos;

	pos = 0;
	while (pos < len)
	{
		array[pos] = '0' + pos;
		pos++;
	}
	ft_increment_digits(array, len);
}

void	ft_print_combn(int n)
{
	char	digit[10];

	if (n > 0 && n < 10)
		ft_initialize_digits(digit, n);
}
