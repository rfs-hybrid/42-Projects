/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:35:41 by maaugust          #+#    #+#             */
/*   Updated: 2025/03/05 20:32:19 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_print_params(int n_params, char **param)
{
	int	i;

	i = 1;
	while (i < n_params)
	{
		while (*param[i])
		{
			write (1, param[i], 1);
			param[i]++;
		}
		write (1, "\n", 1);
		i++;
	}
}

void	ft_sort_params(int n_params, char **param)
{
	int		i;
	int		j;
	char	*temp;

	i = 1;
	while (i < n_params - 1)
	{
		j = i + 1;
		while (j < n_params)
		{
			if (ft_strcmp(param[i], param[j]) > 0)
			{
				temp = param[i];
				param[i] = param[j];
				param[j] = temp;
			}
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		ft_sort_params(argc, argv);
		ft_print_params(argc, argv);
	}
	return (0);
}
