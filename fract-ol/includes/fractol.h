/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:19:25 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/30 19:54:45 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

/* Include libraries*/
# include <stdio.h>
# include <stdbool.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "libft.h"
# include "get_next_line.h"
# include "mlx.h"

/* Screen resolutions */
# define WIDTH_800		800
# define HEIGHT_600		600

# define WIDTH_1024		1024
# define HEIGHT_768		768

# define WIDTH_1280		1280
# define HEIGHT_720		720

# define WIDTH_1680		1680
# define HEIGHT_1050	1050 

/* Complex plane axis*/
# define XMIN			-2.0
# define XMAX			2.0
# define YMIN			-2.0
# define YMAX			2.0

/* Number of color palettes */
# define N_PALETTES		15

/* Fractal types*/
# define MANDELBROT		"MANDELBROT"
# define JULIA			"JULIA"
# define BURNING_SHIP	"BURNING SHIP"
# define TRICORN		"TRICORN"
# define PHOENIX		"PHOENIX"

typedef unsigned char	t_byte;
typedef int				(*t_palette_func)(int iter, int max_iter);

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_data;

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct s_fractal
{
	void			*mlx;
	void			*win;
	t_data			data;
	char			*name;
	int				width;
	int				height;
	int				color;
	double			shade;
	int				iter;
	int				max_iter;
	int				x;
	int				y;
	double			off_x;
	double			off_y;
	double			zoom;
	t_complex		z;
	t_complex		c;
	double			delta;
	bool			is_gray;
	int				palette_idx;
	t_palette_func	palette[N_PALETTES];
	int				n_palettes;
}	t_fractal;

void	ft_init_fractal(t_fractal *frac);
void	ft_mandelbrot(t_fractal *frac);
void	ft_julia(t_fractal *frac);
void	ft_tricorn(t_fractal *frac);
void	ft_burning_ship(t_fractal *frac);
void	ft_phoenix(t_fractal *frac);
void	ft_render_fractal(t_fractal *frac);
int		ft_handle_key_event(int keysym, t_fractal *frac);
int		ft_exit_program(t_fractal *frac);

/* Utility functions */
void	ft_mlx_pixel_put(const t_fractal *frac);
double	ft_absd(double nbr);
char	*ft_strtoupper(char *str);
double	ft_atod(const char *nptr);

/* Palette functions */
int		blue_orange_palette(int iter, int max_iter);
int		rainbow_palette(int iter, int max_iter);
int		fire_palette(int iter, int max_iter);
int		cherry_blossom_palette(int iter, int max_iter);
int		autumn_palette(int iter, int max_iter);
int		sunset_palette(int iter, int max_iter);
int		galaxy_palette(int iter, int max_iter);
int		forest_palette(int iter, int max_iter);
int		hsv_palette(int iter, int max_iter);
int		ice_palette(int iter, int max_iter);
int		deep_ocean_palette(int iter, int max_iter);
int		psychedelic_palette(int iter, int max_iter);
int		shell_palette(int iter, int max_iter);
int		inferno_palette(int iter, int max_iter);
int		dragonfly_palette(int iter, int max_iter);

#endif