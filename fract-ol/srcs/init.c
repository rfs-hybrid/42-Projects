/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 17:01:31 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/30 18:30:25 by maaugust         ###   ########.fr       */
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
		free (frac->mlx);
	}
	ft_putendl_fd("Error: Memory allocation or MLX setup failed!",
		STDERR_FILENO);
	exit(EXIT_FAILURE);
}

static void	set_resolution(t_fractal *frac)
{
	char	*line;

	line = get_next_line(STDIN_FILENO);
	if (!line)
		return (ft_putendl_fd("No input detected. Default resolution applied!",
				STDOUT_FILENO));
	if (!ft_strncmp(line, "2\n", 3))
	{
		frac->width = WIDTH_1024;
		frac->height = HEIGHT_768;
	}
	else if (!ft_strncmp(line, "3\n", 3))
	{
		frac->width = WIDTH_1280;
		frac->height = HEIGHT_720;
	}
	else if (!ft_strncmp(line, "4\n", 3))
	{
		frac->width = WIDTH_1680;
		frac->height = HEIGHT_1050;
	}
	else if (ft_strncmp(line, "1\n", 3))
		ft_putendl_fd("Invalid option. Default resolution applied!",
			STDOUT_FILENO);
	free(line);
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
	frac->shade = 1.0;
	frac->width = WIDTH_800;
	frac->height = HEIGHT_600;
	frac->max_iter = 250;
	frac->off_x = 0.0;
	frac->off_y = 0.0;
	frac->zoom = 1.0;
	frac->is_gray = false;
	frac->palette_idx = 0;
	init_palettes(frac);
}

void	ft_init_fractal(t_fractal *frac)
{
	ft_putendl_fd("Available fractal resolutions:\n", STDOUT_FILENO);
	ft_putendl_fd("\t1 - 800 * 600 (default)", STDOUT_FILENO);
	ft_putendl_fd("\t2 - 1024 * 768", STDOUT_FILENO);
	ft_putendl_fd("\t3 - 1280 * 720", STDOUT_FILENO);
	ft_putendl_fd("\t4 - 1680 * 1050\n", STDOUT_FILENO);
	ft_putstr_fd("Please select one: ", STDOUT_FILENO);
	init_values(frac);
	set_resolution(frac);
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
