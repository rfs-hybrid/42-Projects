/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 17:25:57 by maaugust          #+#    #+#             */
/*   Updated: 2025/07/03 16:35:51 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_exit_program(t_display *disp)
{
	mlx_destroy_image(disp->mlx, disp->data.img);
	mlx_destroy_window(disp->mlx, disp->win);
	mlx_destroy_display(disp->mlx);
	free(disp->mlx);
	exit (EXIT_SUCCESS);
	return (0);
}

char	*ft_strtoupper(char *str)
{
	int	i;

	i = -1;
	while (*(str + ++i))
		str[i] = ft_toupper(str[i]);
	return (str);
}

double	ft_atod(const char *nptr)
{
	double	res;
	double	frac;
	double	div;
	int		sign;

	res = 0.0;
	frac = 0.0;
	div = 10.0;
	sign = 1;
	while (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\r'))
		nptr++;
	while (*nptr == '+' || *nptr == '-')
		if (*nptr++ == '-')
			sign *= -1;
	while (ft_isdigit(*nptr))
		res = res * 10.0 + (*nptr++ - '0');
	if (*nptr == '.')
		nptr++;
	while (ft_isdigit(*nptr))
	{
		frac += (*nptr++ - '0') / div;
		div *= 10;
	}
	return ((res + frac) * sign);
}
