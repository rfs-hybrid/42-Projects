/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:41:02 by maaugust          #+#    #+#             */
/*   Updated: 2025/02/24 12:57:58 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	pos;
	int	aux;

	pos = 0;
	while (pos < size / 2)
	{
		aux = tab[pos];
		tab[pos] = tab[(size - pos) - 1];
		tab[(size - pos) - 1] = aux;
		pos++;
	}
}
