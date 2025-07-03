/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 17:01:31 by maaugust          #+#    #+#             */
/*   Updated: 2025/07/03 20:39:25 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	malloc_error(t_display *disp)
{
	if (disp->mlx)
	{
		if (disp->win)
			mlx_destroy_window(disp->mlx, disp->win);
		mlx_destroy_display(disp->mlx);
		free (disp->mlx);
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
		frac->disp.width = WIDTH_1024;
		frac->disp.height = HEIGHT_768;
	}
	else if (!ft_strncmp(line, "3\n", 3))
	{
		frac->disp.width = WIDTH_1280;
		frac->disp.height = HEIGHT_720;
	}
	else if (!ft_strncmp(line, "4\n", 3))
	{
		frac->disp.width = WIDTH_1680;
		frac->disp.height = HEIGHT_1050;
	}
	else if (ft_strncmp(line, "1\n", 3))
		ft_putendl_fd("Invalid option. Default resolution applied!",
			STDOUT_FILENO);
	free(line);
}

static void	init_palettes(t_fractal *frac)
{
	frac->palette[0] = blue_orange_palette;
	frac->palette[1] = lava_lamp_palette;
	frac->palette[2] = electric_carnival_palette;
	frac->palette[3] = phoenix_glow_palette;
	frac->palette[4] = hsv_palette;
	frac->palette[5] = autumn_palette;
	frac->palette[6] = autumn_frost_palette;
	frac->palette[7] = tropical_sunset_palette;
	frac->palette[8] = winter_sunrise_palette;
	frac->palette[9] = funky_galaxy_palette;
	frac->n_palettes = PALETTE_TOTAL;
	frac->palette_idx = PALETTE_INIT % frac->n_palettes;
}

static void	init_values(t_fractal *frac)
{
	frac->disp.mlx = NULL;
	frac->disp.win = NULL;
	frac->disp.data.img = NULL;
	frac->disp.width = WIDTH_800;
	frac->disp.height = HEIGHT_600;
	frac->shade = SHADE_INIT;
	frac->max_iter = ITER_INIT;
	frac->off_x = OFF_X_INIT;
	frac->off_y = OFF_Y_INIT;
	frac->zoom = ZOOM_INIT;
	frac->is_gray = false;
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
	frac->disp.mlx = mlx_init();
	if (!frac->disp.mlx)
		malloc_error(&frac->disp);
	frac->disp.win = mlx_new_window(frac->disp.mlx, frac->disp.width,
			frac->disp.height, frac->disp.name);
	if (!frac->disp.win)
		malloc_error(&frac->disp);
	frac->disp.data.img = mlx_new_image(frac->disp.mlx, frac->disp.width,
			frac->disp.height);
	if (!frac->disp.data.img)
		malloc_error(&frac->disp);
	frac->disp.data.addr = mlx_get_data_addr(frac->disp.data.img,
			&frac->disp.data.bpp, &frac->disp.data.line_len,
			&frac->disp.data.endian);
}
