/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 01:42:31 by maaugust          #+#    #+#             */
/*   Updated: 2025/07/03 19:06:53 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_fractal_calc(t_fractal *frac)
{
	frac->iter = -1;
	if (!ft_strncmp(frac->disp.name, JULIA, 6))
	{
		frac->z.re = ((XMAX - XMIN) * (double)frac->x / frac->disp.width
				+ XMIN) * frac->zoom + frac->off_x;
		frac->z.im = ((YMAX - YMIN) * (double)frac->y / frac->disp.height
				+ YMIN) * frac->zoom + frac->off_y;
		return ;
	}
	else if (!ft_strncmp(frac->disp.name, PHOENIX, 8)
		|| !ft_strncmp(frac->disp.name, PHOENIX_VARIANT, 16))
	{
		frac->z.re = ((YMAX - YMIN) * (double)frac->y / frac->disp.height
				+ YMIN) * frac->zoom + frac->off_y;
		frac->z.im = ((XMAX - XMIN) * (double)frac->x / frac->disp.width
				+ XMIN) * frac->zoom + frac->off_x;
		return ;
	}
	frac->z.re = 0.0;
	frac->z.im = 0.0;
	frac->c.re = ((XMAX - XMIN) * (double)frac->x / frac->disp.width + XMIN)
		* frac->zoom + frac->off_x;
	frac->c.im = ((YMAX - YMIN) * (double)frac->y / frac->disp.height + YMIN)
		* frac->zoom + frac->off_y;
}

static void	apply_shade(t_fractal *frac)
{
	int				gray;
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;

	if (frac->is_gray)
	{
		gray = (int)((double)frac->iter / frac->max_iter * 255);
		frac->color = (gray << 16) | (gray << 8) | gray;
		return ;
	}
	red = (unsigned char)(((frac->color >> 16) & 0xff) * frac->shade);
	green = (unsigned char)(((frac->color >> 8) & 0xff) * frac->shade);
	blue = (unsigned char)((frac->color & 0xff) * frac->shade);
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

static void	ft_mlx_pixel_put(const t_fractal *frac)
{
	char	*dst;

	if (frac->x < 0 || frac->y < 0 || frac->x >= frac->disp.width
		|| frac->y >= frac->disp.height)
		return ;
	dst = frac->disp.data.addr + (frac->y * frac->disp.data.line_len
			+ frac->x * (frac->disp.data.bpp / 8));
	*(unsigned int *)dst = frac->color;
}

void	ft_render_fractal(t_fractal *frac)
{
	frac->x = -1;
	while (++(frac->x) < frac->disp.width)
	{
		frac->y = -1;
		while (++(frac->y) < frac->disp.height)
		{
			init_fractal_calc(frac);
			if (!ft_strncmp(frac->disp.name, MANDELBROT, 11)
				|| !ft_strncmp(frac->disp.name, JULIA, 6))
				ft_mandelbrot_julia(frac);
			else if (!ft_strncmp(frac->disp.name, TRICORN, 8))
				ft_tricorn(frac);
			else if (!ft_strncmp(frac->disp.name, BURNING_SHIP, 13))
				ft_burning_ship(frac);
			else if (!ft_strncmp(frac->disp.name, PHOENIX, 8))
				ft_phoenix(frac);
			else if (!ft_strncmp(frac->disp.name, PHOENIX_VARIANT, 16))
				ft_phoenix_variant(frac);
			apply_pixel_color(frac);
			ft_mlx_pixel_put(frac);
		}
	}
	mlx_put_image_to_window(frac->disp.mlx, frac->disp.win,
		frac->disp.data.img, 0, 0);
}
