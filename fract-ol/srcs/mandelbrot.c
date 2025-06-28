/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 01:20:16 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/28 20:16:09 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	rescalling(t_fractal *frac)
{
	frac->c.re = ((XMAX - XMIN) * frac->x / frac->width + XMIN) / frac->zoom
				+ frac->off_x;
	frac->c.im = ((YMAX - YMIN) * frac->y / frac->height + YMIN) / frac->zoom
				+ frac->off_y;
}

void	ft_mandelbrot(t_fractal *frac)
{
	double	tmp;

	frac->iter = -1;
	frac->z.re = 0.0;
	frac->z.im = 0.0;
	rescalling(frac);
	while (++frac->iter < frac->max_iter &&
			frac->z.re * frac->z.re + frac->z.im * frac->z.im <= 4.0)
	{
		tmp = frac->z.re * frac->z.re - frac->z.im * frac->z.im  + frac->c.re;
		frac->z.im = 2.0 * frac->z.re * frac->z.im + frac->c.im;
		frac->z.re = tmp;
	}
}
