/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:17:30 by maaugust          #+#    #+#             */
/*   Updated: 2025/03/05 16:48:36 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_next_prime(int nb)
{
	int	i;

	if (nb < 3)
		return (2);
	i = 2;
	while (nb >= 3)
	{
		if (nb % i == 0)
		{
			nb++;
			i = 2;
		}
		else if (i == nb - 1)
			return (nb);
		else
			i++;
	}
	return (2);
}
