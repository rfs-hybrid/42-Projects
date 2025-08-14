/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:32:24 by maaugust          #+#    #+#             */
/*   Updated: 2025/03/05 13:03:32 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	res;

	if (nb < 0)
		res = 0;
	else
	{
		res = 1;
		while (nb > 1)
		{
			res *= nb;
			nb--;
		}
	}
	return (res);
}
