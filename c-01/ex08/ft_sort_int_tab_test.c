/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab_test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:18:58 by maaugust          #+#    #+#             */
/*   Updated: 2025/02/24 16:43:21 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int i;
	int j;
	int aux;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				aux = tab[i];
				tab[i] = tab[j];
				tab[j] = aux;
			}
			j++;
		}
		i++;
	}  
}

int	main(void)
{
	int array[] = {5, 3, 8, 1, 6, 9, 7, 4, 2};
	printf("Before -> array");
	for (int i = 0; i < 9; i++)
		printf("[%d] ", array[i]);
	ft_sort_int_tab(array, 9);
	printf("\nAfter -> array");
	for (int i = 0; i < 9; i++)
		printf("[%d] ", array[i]);
}
