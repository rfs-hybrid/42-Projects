/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 01:42:31 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/28 20:18:40 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	apply_shade(t_fractal *frac)
{
	double	shade;
	int		gray;
	byte	red;
	byte	green;
	byte	blue;

	shade = 1.0 - ((double)frac->shade / frac->max_iter);
	if (frac->is_gray)
	{
		gray = (int)((double)frac->iter / frac->max_iter * 255);
		frac->color = (gray << 16) | (gray << 8) | gray;
		return ;
	}
	red = (byte)(((frac->color >> 16) & 0xff) * shade);
	green = (byte)(((frac->color >> 8) & 0xff) * shade);
	blue = (byte)((frac->color & 0xff) * shade);
	frac->color = (red << 16) | (green << 8) | blue;
}

static void	apply_pixel_color(t_fractal *frac)
{
	if (frac->iter == frac->max_iter)
		frac->color = 0x000000;
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
			if (!ft_strncmp(frac->name, MANDELBROT, 11))
				ft_mandelbrot(frac);
			apply_pixel_color(frac);
			ft_mlx_pixel_put(frac);
		}
	}
	mlx_put_image_to_window(frac->mlx, frac->win, frac->data.img, 0, 0);
}
