/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 19:21:23 by maaugust          #+#    #+#             */
/*   Updated: 2025/04/03 19:28:53 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
