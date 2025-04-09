/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 19:46:31 by maaugust          #+#    #+#             */
/*   Updated: 2025/04/03 19:50:37 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_point.h"

void	set_point(t_point *point)
{
	point->x = 42;
	point->y = 21;
}

int	main(void)
{
	t_point	point;

	point.x = 21;
	point.y = 36;
	printf("x = %d, y = %d\n", point.x, point.y);
	set_point(&point);
	printf("x = %d, y = %d\n", point.x, point.y);
	return (0);
}
