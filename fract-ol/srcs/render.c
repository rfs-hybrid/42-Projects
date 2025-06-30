/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 01:42:31 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/30 18:49:48 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_fractal_calc(t_fractal *frac)
{
	frac->iter = -1;
	if (!ft_strncmp(frac->name, JULIA, 6)
		|| !ft_strncmp(frac->name, PHOENIX, 8))
	{
		frac->z.re = ((XMAX - XMIN) * frac->x / frac->width + XMIN)
			* frac->zoom + frac->off_x;
		frac->z.im = ((YMAX - YMIN) * frac->y / frac->height + YMIN)
			* frac->zoom + frac->off_y;
		return ;
	}
	frac->z.re = 0.0;
	frac->z.im = 0.0;
	frac->c.re = ((XMAX - XMIN) * frac->x / frac->width + XMIN) * frac->zoom
		+ frac->off_x;
	frac->c.im = ((YMAX - YMIN) * frac->y / frac->height + YMIN) * frac->zoom
		+ frac->off_y;
}

static void	apply_shade(t_fractal *frac)
{
	int		gray;
	t_byte	red;
	t_byte	green;
	t_byte	blue;

	if (frac->is_gray)
	{
		gray = (int)((double)frac->iter / frac->max_iter * 255);
		frac->color = (gray << 16) | (gray << 8) | gray;
		return ;
	}
	red = (t_byte)(((frac->color >> 16) & 0xff) * frac->shade);
	green = (t_byte)(((frac->color >> 8) & 0xff) * frac->shade);
	blue = (t_byte)((frac->color & 0xff) * frac->shade);
	frac->color = (red << 16) | (green << 8) | blue;
}

static void	apply_pixel_color(t_fractal *frac)
{
	if (frac->iter == frac->max_iter)
	{
		frac->color = 0x000000;
		return ;
	}
	else if (!frac->is_gray)
		frac->color = frac->palette[frac->palette_idx](frac->iter,
				frac->max_iter);
	apply_shade(frac);
}

void	ft_render_fractal(t_fractal *frac)
{
	frac->x = -1;
	while (++(frac->x) < frac->width)
	{
		frac->y = -1;
		while (++(frac->y) < frac->height)
		{
			init_fractal_calc(frac);
			if (!ft_strncmp(frac->name, MANDELBROT, 11))
				ft_mandelbrot(frac);
			else if (!ft_strncmp(frac->name, JULIA, 6))
				ft_julia(frac);
			else if (!ft_strncmp(frac->name, TRICORN, 8))
				ft_tricorn(frac);
			else if (!ft_strncmp(frac->name, BURNING_SHIP, 13))
				ft_burning_ship(frac);
			else if (!ft_strncmp(frac->name, PHOENIX, 8))
				ft_phoenix(frac);
			apply_pixel_color(frac);
			ft_mlx_pixel_put(frac);
		}
	}
	mlx_put_image_to_window(frac->mlx, frac->win, frac->data.img, 0, 0);
}
