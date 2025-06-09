/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 15:26:32 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/09 19:25:39 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	lis_init(int *lis, int *pred, int max)
{
	int	i;

	i = -1;
	while (++i < max)
	{
		lis[i] = 1;
		pred[i] = -1;
	}
}

static void	calculate_lis(int *lis, int *pred, int *arr, int max)
{
	int	i;
	int	j;

	i = -1;
	while (++i < max)
	{
		lis[i] = 1;
		pred[i] = -1;
	}
	i = 0;
	while (++i < max)
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

static void	get_lis_max_index(int *lis, int max, int *lis_len, int *max_index)
{
	int	i;

	i = 0;
	*lis_len = lis[i];
	*max_index = i;
	while (++i < max)
	{
		if (lis[i] > *lis_len)
		{
			*lis_len = lis[i];
			*max_index = i;
		}
	}
}

static int	*generate_lis(int *pred, int *arr, int lis_len, int max_index)
{
	int	*seq;
	int	i;

	seq = (int *) ft_calloc(lis_len, sizeof(int));
	if (!seq)
		return (NULL);
	i = max_index;
	while (i >= 0)
	{
		seq[--lis_len] = arr[i];
		i = pred[i];
	}
	return (seq);
}

int	*lis_sequence(int *arr, int max, int *lis_len)
{
	int	*lis;
	int	*pred;
	int	*seq;
	int	max_index;

	if (!arr)
		return (NULL);
	lis = (int *) ft_calloc(max, sizeof(int));
	pred = (int *) ft_calloc(max, sizeof(int));
	if (!lis || !pred)
		return (free(lis), free(pred), NULL);
	lis_init(lis, pred, max);
	calculate_lis(lis, pred, arr, max);
	get_lis_max_index(lis, max, lis_len, &max_index);
	seq = generate_lis(pred, arr, *lis_len, max_index);
	return (free(lis), free(pred), seq);
}
