/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palettes2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 18:38:48 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/29 00:43:13 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	sunset_palette(int iter, int max_iter)
{
	double	tmp;
	int		red;
	int		green;
	int		blue;

	tmp = (double)iter / max_iter;
	red = (int)(255 * tmp);
	green = (int)(64 + 128 * (1 - tmp));
	blue = (int)(128 + 64 * (1 - tmp));
	return ((red << 16) | (green << 8) | blue);
}

int	galaxy_palette(int iter, int max_iter)
{
	double	tmp;
	int		red;
	int		green;
	int		blue;

	tmp = (double)iter / max_iter;
	red = (int)(64 * (1 - tmp));
	green = (int)(64 * tmp);
	blue = (int)(128 + 127 * sin(tmp * 6.28));
	return ((red << 16) | (green << 8) | blue);
}

int	forest_palette(int iter, int max_iter)
{
	double	tmp;
	int		red;
	int		green;
	int		blue;

	tmp = (double)iter / max_iter;
	red = (int)(32 * (1 - tmp));
	green = (int)(160 + 95 * tmp);
	blue = (int)(32 + 32 * (1 - tmp));
	return ((red << 16) | (green << 8) | blue);
}

int	hsv_palette(int iter, int max_iter)
{
	double	tmp;
	int		i;
	double	f;
	int		q;
	int		p;

	tmp = (double)iter / max_iter;
	i = (int)(tmp * 6);
	f = tmp * 6 - i;
	q = (int)(255 * (1 - f));
	p = (int)(255 * f);
	if (i % 6 == 0)
		return ((255 << 16) | (p << 8));
	if (i % 6 == 1)
		return ((q << 16) | (255 << 8));
	if (i % 6 == 2)
		return ((0 << 16) | (255 << 8) | p);
	if (i % 6 == 3)
		return ((0 << 16) | (q << 8) | 255);
	if (i % 6 == 4)
		return ((p << 16) | (0 << 8) | 255);
	return ((255 << 16) | (0 << 8) | q);
}

int	ice_palette(int iter, int max_iter)
{
	double	tmp;
	int		red;
	int		green;
	int		blue;

	tmp = (double)iter / max_iter;
	red = (int)(180 + 75 * tmp);
	green = (int)(220 + 35 * tmp);
	blue = (int)(255);
	return ((red << 16) | (green << 8) | blue);
}
