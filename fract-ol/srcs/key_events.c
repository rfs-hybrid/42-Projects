/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:34:41 by maaugust          #+#    #+#             */
/*   Updated: 2025/07/01 14:23:51 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	apply_color_shade(int keysym, t_fractal *frac)
{
	if (keysym == XK_Page_Up && !frac->is_gray)
		frac->palette_idx = (frac->palette_idx + 1) % frac->n_palettes;
	if (keysym == XK_Page_Down && !frac->is_gray)
	{
		if (frac->palette_idx == 0)
			frac->palette_idx = frac->n_palettes;
		frac->palette_idx = (frac->palette_idx - 1) % frac->n_palettes;
	}
	if (keysym == XK_g)
		frac->is_gray = !frac->is_gray;
	if (keysym == XK_Home)
	{
		frac->shade += SHADE_SCALE;
		if (frac->shade > SHADE_MAX)
			frac->shade = SHADE_MAX;
	}
	if (keysym == XK_End)
	{
		frac->shade -= SHADE_SCALE;
		if (frac->shade < SHADE_MIN)
			frac->shade = SHADE_MIN;
	}
}

static void	screen_padding_zoom(int keysym, t_fractal *frac)
{
	if (keysym == XK_w || keysym == XK_Up)
		frac->off_y -= PADDING_SCALE * frac->zoom;
	if (keysym == XK_s || keysym == XK_Down)
		frac->off_y += PADDING_SCALE * frac->zoom;
	if (keysym == XK_a || keysym == XK_Left)
		frac->off_x -= PADDING_SCALE * frac->zoom;
	if (keysym == XK_d || keysym == XK_Right)
		frac->off_x += PADDING_SCALE * frac->zoom;
	if ((keysym == XK_plus || keysym == XK_KP_Add) && frac->zoom > ZOOM_MIN)
		frac->zoom *= ZOOM_SCALE;
	if ((keysym == XK_minus || keysym == XK_KP_Subtract)
		&& frac->zoom < ZOOM_MAX)
		frac->zoom /= ZOOM_SCALE;
	if (keysym == XK_r)
	{
		frac->shade = SHADE_INIT;
		frac->max_iter = ITER_INIT;
		frac->off_x = OFF_X_INIT;
		frac->off_y = OFF_Y_INIT;
		frac->zoom = ZOOM_INIT;
		frac->is_gray = false;
		frac->palette_idx = PALETTE_INIT % frac->n_palettes;
	}
}

static void	update_iterations(int keysym, t_fractal *frac)
{
	if (keysym == XK_q)
	{
		frac->max_iter -= ITER_SCALE;
		if (frac->max_iter < ITER_MIN)
			frac->max_iter = ITER_MIN;
	}
	if (keysym == XK_e)
	{
		frac->max_iter += ITER_SCALE;
		if (frac->max_iter > ITER_MAX)
			frac->max_iter = ITER_MAX;
	}
}

int	ft_handle_key_event(int keysym, t_fractal *frac)
{
	if (keysym == XK_Escape)
		ft_exit_program(&frac->disp);
	if (!ft_strncmp(frac->disp.name, PHOENIX, 8))
	{
		if (keysym == '[')
		{
			frac->delta -= DELTA_SCALE;
			if (frac->delta < DELTA_MIN)
				frac->delta = DELTA_MIN;
		}
		if (keysym == ']')
		{
			frac->delta += DELTA_SCALE;
			if (frac->delta > DELTA_MAX)
				frac->delta = DELTA_MAX;
		}
	}
	apply_color_shade(keysym, frac);
	screen_padding_zoom(keysym, frac);
	update_iterations(keysym, frac);
	ft_render_fractal(frac);
	return (0);
}
