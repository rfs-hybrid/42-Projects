/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 15:26:32 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/12 21:13:44 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	lis_init(int *lis, int *pred, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		lis[i] = 1;
		pred[i] = -1;
	}
}

static void	calculate_lis(int *lis, int *pred, int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (++i < size)
	{
		j = -1;
		while (++j < i)
		{
			if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
			{
				lis[i] = lis[j] + 1;
				pred[i] = j;
			}
		}
	}
}

static void	get_lis_max(int *lis, int size, int *lis_len, int *max)
{
	int	i;

	i = 0;
	*lis_len = lis[i];
	*max = i;
	while (++i < size)
	{
		if (lis[i] > *lis_len)
		{
			*lis_len = lis[i];
			*max = i;
		}
	}
}

static int	*generate_lis(int *pred, int *arr, int lis_len, int max)
{
	int	*seq;
	int	i;

	seq = (int *) ft_calloc(lis_len, sizeof(int));
	if (!seq)
		return (NULL);
	i = max;
	while (i >= 0)
	{
		seq[--lis_len] = arr[i];
		i = pred[i];
	}
	return (seq);
}

int	*ft_lis_sequence(int *arr, int size, int *lis_len)
{
	int	*lis;
	int	*pred;
	int	*seq;
	int	max;

	if (!arr)
		return (NULL);
	lis = (int *) ft_calloc(size, sizeof(int));
	pred = (int *) ft_calloc(size, sizeof(int));
	if (!lis || !pred)
		return (free(lis), free(pred), NULL);
	lis_init(lis, pred, size);
	calculate_lis(lis, pred, arr, size);
	get_lis_max(lis, size, lis_len, &max);
	seq = generate_lis(pred, arr, *lis_len, max);
	return (free(lis), free(pred), seq);
}
