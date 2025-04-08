/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range_test.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:25:41 by maaugust          #+#    #+#             */
/*   Updated: 2025/03/08 16:39:07 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*range = (int *) malloc (sizeof(int) * (max - min));
	if (!*range)
		return (-1);
	i = 0;
	while (i < (max - min))
	{
		(*range)[i] = min + i;
		i++;
	}
	return (max - min);
}

int	main(void)
{
	int *array[4];
	int	i = 0;
	int j;

	while (i < 3)
	{
		j = 0;
		printf("range = %d\n", ft_ultimate_range(&array[i], -4 + i, '0' - i));
		while (j < (('0' - i) - (-4 + i)))
		{
			printf("%d ", array[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("%d\n", ft_ultimate_range(&array[3], 5, -4));
}
