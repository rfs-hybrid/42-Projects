/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 19:21:23 by maaugust          #+#    #+#             */
/*   Updated: 2025/04/03 19:36:30 by maaugust         ###   ########.fr       */
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
	arr = (int *) malloc(sizeof(int) * (max - min));
	if (!arr)
		return (NULL);
	i = -1;
	while (min < max)
		arr[++i] = min++;
	return (arr);
}

int	main(int argc, char **argv)
{
	int	*array;
	int	min;
	int	max;
	int	i;

	if (argc == 3)
	{
		min = atoi(argv[1]);
		max = atoi(argv[2]);
		array = ft_range(min, max);
		i = -1;
		while (++i < max - min)
			printf("%d ", array[i]);
		printf("\n");
		free(array);
	}
	return (0);
}
