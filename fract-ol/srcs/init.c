/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 17:01:31 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/29 00:52:38 by maaugust         ###   ########.fr       */
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

static void	init_palettes(t_fractal *frac)
{
	frac->palette[0] = blue_orange_palette;
	frac->palette[1] = rainbow_palette;
	frac->palette[2] = fire_palette;
	frac->palette[3] = cherry_blossom_palette;
	frac->palette[4] = autumn_palette;
	frac->palette[5] = sunset_palette;
	frac->palette[6] = galaxy_palette;
	frac->palette[7] = forest_palette;
	frac->palette[8] = hsv_palette;
	frac->palette[9] = ice_palette;
	frac->palette[10] = deep_ocean_palette;
	frac->palette[11] = psychedelic_palette;
	frac->palette[12] = shell_palette;
	frac->palette[13] = inferno_palette;
	frac->palette[14] = dragonfly_palette;
	frac->n_palettes = N_PALETTES;
}

static void	init_values(t_fractal *frac)
{
	frac->mlx = NULL;
	frac->win = NULL;
	frac->data.img = NULL;
	frac->color = 0x419F32;
	frac->shade = 0;
	frac->width = WIDTH;
	frac->height = HEIGHT;
	frac->max_iter = 100;
	frac->off_x = 0.0;
	frac->off_y = 0.0;
	frac->zoom = 1.0;
	frac->is_gray = false;
	frac->palette_idx = 0;
	init_palettes(frac);
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
