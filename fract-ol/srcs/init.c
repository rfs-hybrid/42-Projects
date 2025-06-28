/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 17:01:31 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/28 18:13:40 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_malloc_error(t_fractal *frac)
{
	if (frac->mlx)
	{
		if (frac->win)
			mlx_destroy_window(frac->mlx, frac->win);
		mlx_destroy_display(frac->mlx);
	}
	ft_putendl_fd("Error: Memory allocation or MLX setup failed!",
		STDERR_FILENO);
	exit(EXIT_FAILURE);
}

static void	init_values(t_fractal *frac)
{
	frac->mlx = NULL;
	frac->win = NULL;
	frac->data.img = NULL;
	frac->color = 0x419F32;
	frac->width = WIDTH;
	frac->height = HEIGHT;
	frac->max_iter = 100;
	frac->off_x = 0.0;
	frac->off_y = 0.0;
	frac->zoom = 1.0;
}

void	ft_init_fractal(t_fractal *frac)
{
	init_values(frac);
	frac->mlx = mlx_init();
	if (!frac->mlx)
		ft_malloc_error(frac);
	frac->win = mlx_new_window(frac->mlx, frac->width, frac->height,
			frac->name);
	if (!frac->win)
		ft_malloc_error(frac);
	frac->data.img = mlx_new_image(frac->mlx, frac->width, frac->height);
	if (!frac->data.img)
		ft_malloc_error(frac);
	frac->data.addr = mlx_get_data_addr(frac->data.img, &frac->data.bpp,
			&frac->data.line_len, &frac->data.endian);
}
