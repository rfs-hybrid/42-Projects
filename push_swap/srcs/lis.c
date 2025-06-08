/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 15:26:32 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/07 15:47:26 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	initialize_lis(int **lis, int **pred)
{
	int	i;

	lis = (int *) ft_calloc(max, sizeof(int));
	pred = (int *) ft_calloc(max, sizeof(int));
	if (!lis || !pred)
	{
		free (lis);
		free (pred);
		return (false);
	}
	i = -1;
	while (++i < max)
	{
		lis[i] = 1;
		pred[i] = -1;
	}
	return (true);
}

static void	compute_lis(int **lis, int **pred, int *arr, int max)
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
			if (arr[i] > arr[j] && *(lis[i]) < *(lis[j]) + 1)
			{
				*(lis[i]) = *(lis[j]) + 1;
				*(pred[i]) = j;
			}
		}
	}
}

static void	get_max_index(int *lis, int max, int *max_len, int *max_index)
{
	int	i;

	i = 0;
	*max_len = lis[i];
	*max_index = i;
	while (++i < max)
	{
		if (lis[i] > *max_len)
		{
			*max_len = lis[i];
			*max_index = i;
		}
	}
}

static int	*reconstruct_lis(int *pred, int *arr, int max_len, int max_index)
{
	int	*seq;
	int	i;

	seq = (int *) ft_calloc(max_len, sizeof(int));
	if (!seq)
		return (NULL);
	i = max_index;
	while (i >= 0)
	{
		seq[--max_len] = arr[i];
		i = pred[i];
	}
	return (seq);
}

int	*lis_sequence (int *arr, int max)
{
	int	*lis;
	int	*pred;
	int	*seq;
	int	max_len;
	int	max_index;

	if (!(initialize_lis(&lis, &pred)))
		return (NULL);
	compute_lis(&lis, &pred, arr, max);
	get_max_index(lis, max, &max_len, &max_index);
	seq = reconstruct_lis(pred, arr, max_len, max_index);
	free (lis);
	free (pred);
	return (seq);
}
