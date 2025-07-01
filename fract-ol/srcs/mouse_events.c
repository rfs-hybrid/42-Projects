/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:45:23 by maaugust          #+#    #+#             */
/*   Updated: 2025/07/01 13:12:18 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	screen_zoom(int button, int x, int y, t_fractal *frac)
{
	double	prev_off_re;
	double	prev_off_im;

	prev_off_re = ((XMAX - XMIN) * (double)x / frac->width + XMIN) * frac->zoom
		+ frac->off_x;
	prev_off_im = ((YMAX - YMIN) * (double)y / frac->height + YMIN) * frac->zoom
		+ frac->off_y;
	if (button == MOUSE_SCROLL_UP)
		frac->zoom *= ZOOM_SCALE;
	if (button == MOUSE_SCROLL_DOWN)
		frac->zoom /= ZOOM_SCALE;
	frac->off_x = prev_off_re - ((XMAX - XMIN) * x / frac->width + XMIN)
		* frac->zoom;
	frac->off_y = prev_off_im - ((YMAX - YMIN) * y / frac->height + YMIN)
		* frac->zoom;
}

int	ft_handle_mouse_event(int button, int x, int y, t_fractal *frac)
{
	if ((button == MOUSE_SCROLL_UP && frac->zoom > ZOOM_MIN)
		|| (button == MOUSE_SCROLL_DOWN && frac->zoom < ZOOM_MAX))
		screen_zoom(button, x, y, frac);
	ft_render_fractal(frac);
	return (0);
}
