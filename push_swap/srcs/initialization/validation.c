/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:34:36 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/26 15:45:36 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	check_is_num(char **words)
{
	int	i;
	int	j;

	i = -1;
	while (words[++i])
	{
		j = -1;
		while (words[i][++j])
		{
			if (j == 0 && (words[i][0] == '-' || words[i][0] == '+'))
				j++;
			if (!ft_isdigit(words[i][j]))
				return (false);
		}
	}
	return (true);
}

static bool	check_duplicates(char **words)
{
	int	i;
	int	j;

	i = -1;
	while (words[++i])
	{
		j = i;
		while (words[++j])
		{
			if (ft_atoi(words[i]) == ft_atoi(words[j]))
				return (false);
		}
	}
	return (true);
}

static bool	check_is_int(char **words)
{
	long	nbr;
	int		i;

	i = -1;
	while (words[++i])
	{
		nbr = ft_atol(words[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			return (false);
	}
	return (true);
}

bool	ft_validation(char **words)
{
	return (check_is_num(words) && check_duplicates(words)
		&& check_is_int(words));
}
