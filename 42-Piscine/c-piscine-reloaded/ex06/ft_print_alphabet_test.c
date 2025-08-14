/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet_test.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:02:43 by maaugust          #+#    #+#             */
/*   Updated: 2025/04/02 13:07:57 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_print_alphabet(void)
{
	char	c;

	c = 'a';
	while (c <= 'z')
		ft_putchar(c++);
}

int	main(void)
{
	ft_print_alphabet();
}
