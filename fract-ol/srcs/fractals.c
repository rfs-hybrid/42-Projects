/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 01:20:16 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/30 18:50:21 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mandelbrot(t_fractal *frac)
{
	double	tmp;

	while (++frac->iter < frac->max_iter
		&& frac->z.re * frac->z.re + frac->z.im * frac->z.im <= XMAX * YMAX)
	{
		tmp = frac->z.re * frac->z.re - frac->z.im * frac->z.im + frac->c.re;
		frac->z.im = 2.0 * frac->z.re * frac->z.im + frac->c.im;
		frac->z.re = tmp;
	}
}

void	ft_julia(t_fractal *frac)
{
	double	tmp;

	while (++frac->iter < frac->max_iter
		&& frac->z.re * frac->z.re + frac->z.im * frac->z.im <= XMAX * YMAX)
	{
		tmp = frac->z.re * frac->z.re - frac->z.im * frac->z.im + frac->c.re;
		frac->z.im = 2.0 * frac->z.re * frac->z.im + frac->c.im;
		frac->z.re = tmp;
	}
}

void	ft_tricorn(t_fractal *frac)
{
	double	tmp;

	while (++frac->iter < frac->max_iter
		&& frac->z.re * frac->z.re + frac->z.im * frac->z.im <= XMAX * YMAX)
	{
		tmp = frac->z.re * frac->z.re - frac->z.im * frac->z.im + frac->c.re;
		frac->z.im = -2.0 * frac->z.re * frac->z.im + frac->c.im;
		frac->z.re = tmp;
	}
}

void	ft_burning_ship(t_fractal *frac)
{
	double	tmp;

	while (++frac->iter < frac->max_iter
		&& frac->z.re * frac->z.re + frac->z.im * frac->z.im <= XMAX * YMAX)
	{
		tmp = ft_absd(frac->z.re * frac->z.re
				- frac->z.im * frac->z.im + frac->c.re);
		frac->z.im = ft_absd(2.0 * frac->z.re * frac->z.im + frac->c.im);
		frac->z.re = tmp;
	}
}
