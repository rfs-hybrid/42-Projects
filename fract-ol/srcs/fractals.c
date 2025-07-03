/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 01:20:16 by maaugust          #+#    #+#             */
/*   Updated: 2025/07/03 19:29:12 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mandelbrot_julia(t_fractal *frac)
{
	double	tmp;

	while (++frac->iter < frac->max_iter
		&& frac->z.re * frac->z.re + frac->z.im * frac->z.im <= FRAC_LIMIT)
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
		&& frac->z.re * frac->z.re + frac->z.im * frac->z.im <= FRAC_LIMIT)
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
		&& frac->z.re * frac->z.re + frac->z.im * frac->z.im <= FRAC_LIMIT)
	{
		tmp = fabs(frac->z.re * frac->z.re - frac->z.im * frac->z.im
				+ frac->c.re);
		frac->z.im = fabs(2.0 * frac->z.re * frac->z.im + frac->c.im);
		frac->z.re = tmp;
	}
}

void	ft_phoenix(t_fractal *frac)
{
	double	prev_re;
	double	prev_im;
	double	curr_re;
	double	curr_im;

	prev_re = 0.0;
	prev_im = 0.0;
	while (++frac->iter < frac->max_iter
		&& frac->z.re * frac->z.re + frac->z.im * frac->z.im <= FRAC_LIMIT)
	{
		curr_re = frac->z.re;
		curr_im = frac->z.im;
		frac->z.re = curr_re * curr_re - curr_im * curr_im + frac->c.re
			+ frac->delta * prev_re;
		frac->z.im = 2.0 * curr_re * curr_im + frac->delta * prev_im;
		prev_re = curr_re;
		prev_im = curr_im;
	}
}

void	ft_phoenix_variant(t_fractal *frac)
{
	double	tmp;
	double	prev_re;
	double	prev_im;

	prev_re = frac->z.re;
	prev_im = frac->z.im;
	while (++frac->iter < frac->max_iter
		&& frac->z.re * frac->z.re + frac->z.im * frac->z.im <= FRAC_LIMIT)
	{
		tmp = frac->z.re * frac->z.re - frac->z.im * frac->z.im
			+ frac->c.re + frac->delta * prev_re;
		prev_im = frac->z.im;
		frac->z.im = 2.0 * frac->z.re * frac->z.im + frac->delta * prev_im;
		prev_re = frac->z.re;
		frac->z.re = tmp;
	}
}
