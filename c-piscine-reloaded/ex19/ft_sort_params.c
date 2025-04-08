/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 18:34:11 by maaugust          #+#    #+#             */
/*   Updated: 2025/04/03 19:09:46 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int	ft_strcmp(char *str1, char *str2)
{
	unsigned int	i;

	i = 0;
	while (str1[i] && str1[i] == str2[i])
		i++;
	return (str1[i] - str2[i]);
}

void	ft_print_params(int n_params, char **params)
{
	int	i;
	int	j;

	i = 0;
	while (++i < n_params)
	{
		j = -1;
		while (params[i][++j])
			ft_putchar(params[i][j]);
		ft_putchar('\n');
	}
}

void	ft_sort_params(int n_params, char **params)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (++i < n_params - 1)
	{
		j = i;
		while (++j < n_params)
		{
			if (ft_strcmp(params[i], params[j]) > 0)
			{
				tmp = params[i];
				params[i] = params[j];
				params[j] = tmp;
			}
		}
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
