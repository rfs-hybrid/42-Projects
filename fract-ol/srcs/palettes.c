/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palettes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 18:38:52 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/28 20:18:58 by maaugust         ###   ########.fr       */
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

int	pastel_palette(int iter, int max_iter)
{
	double	tmp;
	int		red;
	int		green;
	int		blue;

	tmp = (double)iter / max_iter;
	red = (int)(128 + 127 * sin(3.0 * tmp));
	green = (int)(128 + 127 * sin(3.0 * tmp + 2.0));
	blue = (int)(128 + 127 * sin(3.0 * tmp + 4.0));
	return ((red << 16) | (green << 8) | blue);
}

int	dreamy_pastel_palette(int iter, int max_iter)
{
	double	tmp;
	int		red;
	int		green;
	int		blue;

	tmp = (double)iter / max_iter;
	red = (int)(200 + 55 * sin(3.0 * tmp));
	green = (int)(180 + 75 * sin(2.0 * tmp + 2));
	blue = (int)(220 + 35 * cos(4.0 * tmp));
	return ((red << 16) | (green << 8) | blue);
}
