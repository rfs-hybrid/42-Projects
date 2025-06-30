/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palettes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 18:38:52 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/30 14:59:23 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	blue_orange_palette(int iter, int max_iter)
{
	double	tmp;
	int		red;
	int		green;
	int		blue;

	tmp = (double)iter / max_iter;
	red = (int)(9 * (1 - tmp) * tmp * tmp * tmp * 255);
	green = (int)(15 * (1 - tmp) * (1 - tmp) * tmp * tmp * 255);
	blue = (int)(8.5 * (1 - tmp) * (1 - tmp) * (1 - tmp) * tmp * 255);
	return ((red << 16) | (green << 8) | blue);
}

int	rainbow_palette(int iter, int max_iter)
{
	int	red;
	int	green;
	int	blue;

	(void) max_iter;
	red = (int)(sin(0.016 * iter + 4) * 230 + 25);
	green = (int)(sin(0.013 * iter + 2) * 230 + 25);
	blue = (int)(sin(0.01 * iter + 1) * 230 + 25);
	return ((red << 16) | (green << 8) | blue);
}

int	fire_palette(int iter, int max_iter)
{
	double	tmp;
	int		red;
	int		green;
	int		blue;

	tmp = (double)iter / max_iter;
	red = (int)(tmp * 255);
	green = (int)(tmp * tmp * 255);
	blue = (int)(tmp * tmp * tmp * 128);
	return ((red << 16) | (green << 8) | blue);
}

int	cherry_blossom_palette(int iter, int max_iter)
{
	double	tmp;
	int		red;
	int		green;
	int		blue;

	tmp = (double)iter / max_iter;
	red = (int)(255 * pow(tmp, 1.2));
	green = (int)(150 * pow(tmp, 2) * (1 - tmp));
	blue = (int)(180 * (1 - pow(tmp, 1.5)));
	return ((red << 16) | (green << 8) | blue);
}

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
