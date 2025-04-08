/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:28:16 by maaugust          #+#    #+#             */
/*   Updated: 2025/02/24 19:40:09 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	result;
	int	remainder;

	result = 0;
	remainder = 0;
	if (*b != 0)
	{
		result = *a / *b;
		remainder = *a % *b;
		*a = result;
		*b = remainder;
	}
}
