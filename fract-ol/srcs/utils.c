/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 17:25:57 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/28 20:17:45 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mlx_pixel_put(const t_fractal *frac)
{
	char	*dst;

	if (frac->x < 0 || frac->y < 0 || frac->x >= frac->width
		|| frac->y >= frac->height)
		return ;
	dst = frac->data.addr + (frac->y * frac->data.line_len
		+ frac->x * (frac->data.bpp / 8));
	*(unsigned int*)dst = frac->color;
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
