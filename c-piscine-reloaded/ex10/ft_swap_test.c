/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:57:07 by maaugust          #+#    #+#             */
/*   Updated: 2025/04/02 14:13:14 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	main(void)
{
	int	a = -12;
	int	b = 27;

	printf("Before: a == %d, b == %d\n", a, b);
	ft_swap(&a, &b);
	printf("After : a == %d, b == %d\n", a, b);
	return (0);
}
