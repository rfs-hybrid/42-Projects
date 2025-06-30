/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palettes3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 23:36:28 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/30 12:23:40 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	deep_ocean_palette(int iter, int max_iter)
{
	double	tmp;
	int		red;
	int		green;
	int		blue;

	tmp = (double)iter / max_iter;
	red = (int)(30 * (1 - tmp));
	green = (int)(100 * pow(tmp, 0.8));
	blue = (int)(200 * pow(tmp, 1.5) + 55);
	return ((red << 16) | (green << 8) | blue);
}

int	psychedelic_palette(int iter, int max_iter)
{
	double	tmp;
	int		red;
	int		green;
	int		blue;

	tmp = (double)iter / max_iter;
	red = (int)(255 * (0.5 + 0.5 * sin(6.2831 * tmp + 0)));
	green = (int)(255 * (0.5 + 0.5 * sin(6.2831 * tmp + 2)));
	blue = (int)(255 * (0.5 + 0.5 * sin(6.2831 * tmp + 4)));
	return ((red << 16) | (green << 8) | blue);
}

int	shell_palette(int iter, int max_iter)
{
	double	tmp;
	int		red;
	int		green;
	int		blue;

	tmp = (double)iter / max_iter;
	red = (int)(200 * tmp * tmp);
	green = (int)(150 * sqrt(tmp));
	blue = (int)(255 * (1 - tmp) * tmp);
	return ((red << 16) | (green << 8) | blue);
}

int	inferno_palette(int iter, int max_iter)
{
	double	tmp;
	int		red;
	int		green;
	int		blue;

	tmp = (double)iter / max_iter;
	red = (int)(255 * pow(tmp, 0.3));
	green = (int)(150 * pow(tmp, 2));
	blue = (int)(50 * pow(tmp, 4));
	return ((red << 16) | (green << 8) | blue);
}

int	dragonfly_palette(int iter, int max_iter)
{
	double	tmp;
	int		red;
	int		green;
	int		blue;

	tmp = (double)iter / max_iter;
	red = (int)(100 * (1 - tmp) * sin(5 * 3.1415 * tmp) + 150);
	green = (int)(200 * pow(tmp, 1.2));
	blue = (int)(255 * (1 - pow(tmp, 2)));
	return ((red << 16) | (green << 8) | blue);
}
