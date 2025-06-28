/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:19:25 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/29 00:52:34 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdbool.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "libft.h"
# include "mlx.h"

# define WIDTH		800
# define HEIGHT		600
# define XMIN		-2.0
# define XMAX		2.0
# define YMIN		-2.0
# define YMAX		2.0

# define MANDELBROT		"MANDELBROT"
# define JULIA			"JULIA"
# define BURNING_SHIP	"BURNING SHIP"
# define TRICORN		"TRICORN"

# define N_PALETTES	15

typedef unsigned char	byte;
typedef int	(*t_palette_func)(int iter, int max_iter);

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
	int				shade;
	int				iter;
	int				max_iter;
	int				x;
	int				y;
	double			off_x;
	double			off_y;
	double			zoom;
	t_complex		z;
	t_complex		c;
	bool			is_gray;
	int				palette_idx;
	t_palette_func	palette[N_PALETTES];
	int				n_palettes;
}	t_fractal;

void	ft_init_fractal(t_fractal *frac);
void	ft_mlx_pixel_put(const t_fractal *frac);
void	ft_mandelbrot(t_fractal *frac);
void	ft_render_fractal(t_fractal *frac);
int		ft_handle_key_event(int keysym, t_fractal *frac);

/* Utility functions */
char	*ft_strtoupper(char *str);
double	ft_atod(const char *nptr);

/* Palette functions */
int	blue_orange_palette(int iter, int max_iter);
int	rainbow_palette(int iter, int max_iter);
int	fire_palette(int iter, int max_iter);
int	cherry_blossom_palette(int iter, int max_iter);
int	autumn_palette(int iter, int max_iter);
int	sunset_palette(int iter, int max_iter);
int	galaxy_palette(int iter, int max_iter);
int	forest_palette(int iter, int max_iter);
int	hsv_palette(int iter, int max_iter);
int	ice_palette(int iter, int max_iter);
int deep_ocean_palette(int iter, int max_iter);
int	psychedelic_palette(int iter, int max_iter);
int	shell_palette(int iter, int max_iter);
int	inferno_palette(int iter, int max_iter);
int	dragonfly_palette(int iter, int max_iter);

#endif