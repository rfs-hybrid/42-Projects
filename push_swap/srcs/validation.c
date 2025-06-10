/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:34:36 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/10 14:45:06 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_is_int(char **words, int is_argv)
{
	long	nbr;
	int		i;

	i = -1;
	while (words[++i])
	{
		nbr = ft_atol(words[i]);
		if (nbr > 2147483647 || nbr < -2147483648)
		{
			if (!is_argv)
				ft_free_words(words);
			ft_print_error();
		}
	}
}

static void	check_duplicates(char **words, bool is_argv)
{
	int	i;
	int	j;

	i = -1;
	while (words[++i])
	{
		j = i;
		while (words[++j])
		{
			if (!ft_strcmp(words[i], words[j]))
			{
				if (!is_argv)
					ft_free_words(words);
				ft_print_error();
			}
		}
	}
}

static void	check_is_num(char **words, bool is_argv)
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
			{
				if (!is_argv)
					ft_free_words(words);
				ft_print_error();
			}
		}
	}
}

void	validation(char **words, bool is_argv)
{
	check_is_num(words, is_argv);
	check_duplicates(words, is_argv);
	check_is_int(words, is_argv);
}
