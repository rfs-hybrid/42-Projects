/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:19:25 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/28 18:10:56 by maaugust         ###   ########.fr       */
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

typedef unsigned char	byte;

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
	void		*mlx;
	void		*win;
	t_data		data;
	char		*name;
	int			width;
	int			height;
	int			color;
	int			max_iter;
	int			x;
	int			y;
	double		off_x;
	double		off_y;
	double		zoom;
	t_complex	z;
	t_complex	c;
}	t_fractal;

void	ft_init_fractal(t_fractal *frac);
void	ft_mlx_pixel_put(const t_fractal *frac);
void	ft_apply_shade(t_fractal *frac, int iter, bool is_gray);
void	ft_mandelbrot(t_fractal *frac);
void	ft_render_fractal(t_fractal *frac);
// void	apply_shade(t_fractal *frac, bool is_gray);
int		ft_handle_key_event(int keysym, t_fractal *frac);

/* Utility functions */
char	*ft_strtoupper(char *str);
double	ft_atod(const char *nptr);

#endif