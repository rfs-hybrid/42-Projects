/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:41:02 by maaugust          #+#    #+#             */
/*   Updated: 2025/02/24 12:56:45 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

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

int	main(void)
{
	int	i;
	int	array[8];

	i = 0;
	while (i < 8)
	{
		array[i] = i + 1;
		i++;
	}
	i = 0;
	printf ("Before -> array");
	while (i < 8)
	{
		printf ("[%d] ", array[i]);
		i++;
	}
	ft_rev_int_tab(array, 8);
	i = 0;
	printf("\nAfter -> array");
	while (i < 8)
	{
		printf ("[%d] ", array[i]);
		i++;
	}
	printf("\n");
}
