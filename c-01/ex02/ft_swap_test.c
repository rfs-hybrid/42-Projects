/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:35:36 by maaugust          #+#    #+#             */
/*   Updated: 2025/02/21 13:04:39 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	aux;

	aux = *a;
	*a = *b;
	*b = aux;
}

int	main(void)
{
	int	n1;
	int	n2;

	n1 = 12;
	n2 = 27;
	printf("Before swap -> n1: %d, n2: %d\n", n1, n2);
	ft_swap(&n1, &n2);
	printf("After swap-> n1: %d, n2: %d\n", n1, n2);
}
