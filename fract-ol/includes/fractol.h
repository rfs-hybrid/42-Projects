/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:19:25 by maaugust          #+#    #+#             */
/*   Updated: 2025/07/01 13:53:48 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

/* Include libraries */
# include <stdbool.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "libft.h"
# include "get_next_line.h"
# include "mlx.h"

/* Screen resolutions definitions */
# define WIDTH_800			800
# define HEIGHT_600			600

# define WIDTH_1024			1024
# define HEIGHT_768			768

# define WIDTH_1280			1280
# define HEIGHT_720			720

# define WIDTH_1680			1680
# define HEIGHT_1050		1050 

/* Complex plane definitions */
# define XMIN				-2.0
# define XMAX				2.0

# define YMIN				-2.0
# define YMAX				2.0

# define OFF_X_INIT			0.0
# define OFF_Y_INIT			0.0

# define FRAC_LIMIT			4.0

/* Palette definitions */
# define PALETTE_INIT		0
# define PALETTE_TOTAL		15

/* Zoom definitions */
# define ZOOM_SCALE			0.9
# define ZOOM_MIN			1.0e-9
# define ZOOM_MAX			5.0
# define ZOOM_INIT			1.0

/* Shading definitions */
# define SHADE_SCALE		0.1
# define SHADE_MIN			0.0
# define SHADE_MAX			1.0
# define SHADE_INIT			1.0

/* Padding definitions */
# define PADDING_SCALE		0.25

/* Iteration definitions */
# define ITER_SCALE			25
# define ITER_MIN			25
# define ITER_MAX			1000
# define ITER_INIT			100

/* Delta definitions */
# define DELTA_SCALE		0.02
# define DELTA_MIN			-1.0
# define DELTA_MAX			1.0

/* Mouse button definitions*/
# define MOUSE_LEFT      	1
# define MOUSE_RIGHT     	2
# define MOUSE_MIDDLE    	3
# define MOUSE_SCROLL_UP 	4
# define MOUSE_SCROLL_DOWN	5

/* Fractal types*/
# define MANDELBROT			"MANDELBROT"
# define JULIA				"JULIA"
# define BURNING_SHIP		"BURNING SHIP"
# define TRICORN			"TRICORN"
# define PHOENIX			"PHOENIX"

/* Typedef for palette function pointer*/
typedef int	(*t_palette_func)(int iter, int max_iter);

/* MLX image data struct */
typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_data;

/* Complex numbers struct*/
typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

/* Fractal struct */
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
	t_palette_func	palette[PALETTE_TOTAL];
	int				n_palettes;
}	t_fractal;

/* Initialization functions */
void	ft_init_fractal(t_fractal *frac);

/* Rendering functions */
void	ft_render_fractal(t_fractal *frac);

/* Event handling functions */
int		ft_handle_key_event(int keysym, t_fractal *frac);
int		ft_handle_mouse_event(int button, int x, int y, t_fractal *frac);

/* Fractal functions */
void	ft_mandelbrot_julia(t_fractal *frac);
void	ft_tricorn(t_fractal *frac);
void	ft_burning_ship(t_fractal *frac);
void	ft_phoenix(t_fractal *frac);

/* Utility functions */
int		ft_exit_program(t_fractal *frac);
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