/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 01:42:31 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/28 17:18:36 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
		}
	}
	mlx_put_image_to_window(frac->mlx, frac->win, frac->data.img, 0, 0);
}
