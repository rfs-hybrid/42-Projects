/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:50:02 by maaugust          #+#    #+#             */
/*   Updated: 2025/03/10 18:45:55 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	i;

	if (min >= max)
		return (NULL);
	arr = (int *) malloc (sizeof(int) * (max - min));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < (max - min))
	{
		arr[i] = min + i;
		i++;
	}
	return (arr);
}

int	main(void)
{
	int	i = 0;
	int	min = -12;
	int max = 24;
	int *arr = ft_range(min, max);

	while (i < (max - min))
	{
		printf ("%d ", arr[i]);
		i++;
	}
	printf ("\n");
	return (0);
}
