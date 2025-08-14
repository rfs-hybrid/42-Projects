/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 21:11:36 by maaugust          #+#    #+#             */
/*   Updated: 2025/04/03 21:20:07 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putstr(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	write(1, "\n", 1);
	return (1);
}

int	ft_count_if(char **tab, int (*f)(char *))
{
	int	cnt;
	int	i;

	cnt = 0;
	i = -1;
	while (tab[++i])
	{
		if (f(tab[i]))
			cnt++;
	}
	return (cnt);
}

int	main(int argc, char **argv)
{
	(void)argc;
	ft_count_if(argv, &ft_putstr);
	return (0);
}
