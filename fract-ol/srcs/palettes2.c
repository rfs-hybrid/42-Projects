/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palettes2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 18:38:48 by maaugust          #+#    #+#             */
/*   Updated: 2025/07/03 20:47:22 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	autumn_palette(int iter, int max_iter)
{
	double	tmp;
	int		red;
	int		green;
	int		blue;

	tmp = (double)iter / max_iter;
	red = (int)(15 * (1 - tmp) * tmp * tmp * 255);
	green = (int)(8 * (1 - tmp) * (1 - tmp) * tmp * 255);
	blue = (int)(3 * (1 - tmp) * (1 - tmp) * (1 - tmp) * 255);
	return ((red << 16) | (green << 8) | blue);
}

int	autumn_frost_palette(int iter, int max_iter)
{
	double	tmp;
	int		red;
	int		green;
	int		blue;

	tmp = (double)iter / max_iter;
	red = (int)(15 * (1 - tmp) * tmp * tmp * 255);
	red = (int)((0.7 * red)
			+ (0.3 * (50 * (0.5 + 0.5 * sin(6.2831 * tmp + 4)))));
	green = (int)(8 * (1 - tmp) * (1 - tmp) * tmp * 255);
	green = (int)((0.8 * green)
			+ (0.2 * (100 * (0.5 + 0.5 * sin(6.2831 * tmp + 2)))));
	blue = (int)(3 * (1 - tmp) * (1 - tmp) * (1 - tmp) * 255);
	blue = (int)((0.7 * blue)
			+ (0.3 * (100 * (0.5 + 0.5 * sin(6.2831 * tmp + 2)))));
	return ((red << 16) | (green << 8) | blue);
}

int	tropical_sunset_palette(int iter, int max_iter)
{
	double	tmp;
	int		red;
	int		green;
	int		blue;

	tmp = (double)iter / max_iter;
	red = (int)(255 * (0.5 + 0.5 * sin(6.2831 * tmp + 0)));
	red = (int)((0.8 * red) + (0.2 * (200 * tmp * (1 - tmp) * 255)));
	green = (int)(255 * (0.5 + 0.5 * sin(6.2831 * tmp + 2)));
	green = (int)((0.8 * green) + (0.2 * (200 * tmp * (1 - tmp) * 255)));
	blue = (int)(255 * (0.5 + 0.5 * sin(6.2831 * tmp + 4)));
	blue = (int)((0.8 * blue) + (0.2 * (200 * tmp * (1 - tmp) * 255)));
	return ((red << 16) | (green << 8) | blue);
}

int	winter_sunrise_palette(int iter, int max_iter)
{
	double	tmp;
	int		red;
	int		green;
	int		blue;

	tmp = (double)iter / max_iter;
	red = (int)(255 * (1 - tmp) * tmp * tmp * 255);
	red = (int)((0.7 * red)
			+ (0.3 * (100 * (0.5 + 0.5 * sin(6.2831 * tmp + 4)))));
	green = (int)(100 * (1 - tmp) * (1 - tmp) * tmp * 255);
	green = (int)((0.8 * green)
			+ (0.2 * (150 * (0.5 + 0.5 * sin(6.2831 * tmp + 2)))));
	blue = (int)(50 * (1 - tmp) * (1 - tmp) * (1 - tmp) * 255);
	blue = (int)((0.7 * blue)
			+ (0.3 * (150 * (0.5 + 0.5 * sin(6.2831 * tmp + 2)))));
	return ((red << 16) | (green << 8) | blue);
}

int	funky_galaxy_palette(int iter, int max_iter)
{
	double	tmp;
	int		red;
	int		green;
	int		blue;

	tmp = (double)iter / max_iter;
	red = (int)(100 * (1 - tmp) * tmp * 255);
	red = (int)((0.8 * red) + (0.2 * (255 * (0.5 + 0.5 * sin(10 * tmp)))));
	green = (int)(50 * (1 - tmp) * (1 - tmp) * tmp * 255);
	green = (int)((0.8 * green) + (0.2 * (255 * (0.5 + 0.5 * sin(10 * tmp)))));
	blue = (int)(200 * (1 - tmp) * (1 - tmp) * (1 - tmp) * 255);
	blue = (int)((0.8 * blue) + (0.2 * (255 * (0.5 + 0.5 * sin(10 * tmp)))));
	return ((red << 16) | (green << 8) | blue);
}
