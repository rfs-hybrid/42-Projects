/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:34:41 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/30 20:13:46 by maaugust         ###   ########.fr       */
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
		frac->shade += 0.1;
		if (frac->shade > 1.0)
			frac->shade = 1.0;
	}
	if (keysym == XK_End)
	{
		frac->shade -= 0.1;
		if (frac->shade < 0.0)
			frac->shade = 0.0;
	}
}

static void	apply_zoom_in_out(int keysym, t_fractal *frac)
{
	if (keysym == XK_plus || keysym == XK_KP_Add)
	{
		frac->zoom *= 0.95;
		if (frac->zoom > 1.0)
			frac->zoom = 1.0;
	}
	if (keysym == XK_minus || keysym == XK_KP_Subtract)
	{
		frac->zoom /= 0.95;
		if (frac->zoom > 1.0)
			frac->zoom = 1.0;
	}
}

static void	move_reset_screen(int keysym, t_fractal *frac)
{
	if (keysym == XK_w || keysym == XK_Up)
		frac->off_y -= 0.25 * frac->zoom;
	if (keysym == XK_s || keysym == XK_Down)
		frac->off_y += 0.25 * frac->zoom;
	if (keysym == XK_a || keysym == XK_Left)
		frac->off_x -= 0.25 * frac->zoom;
	if (keysym == XK_d || keysym == XK_Right)
		frac->off_x += 0.25 * frac->zoom;
	if (keysym == XK_r)
	{
		frac->shade = 1.0;
		frac->max_iter = 100;
		frac->off_x = 0.0;
		frac->off_y = 0.0;
		frac->zoom = 1.0;
		frac->is_gray = false;
		frac->palette_idx = 0;
	}
}

static void	update_iterations(int keysym, t_fractal *frac)
{
	if (keysym == XK_q)
	{
		frac->max_iter -= 25;
		if (frac->max_iter <= 0)
			frac->max_iter = 25;
	}
	if (keysym == XK_e)
	{
		frac->max_iter += 25;
		if (frac->max_iter >= 500)
			frac->max_iter = 500;
	}
}

int	ft_handle_key_event(int keysym, t_fractal *frac)
{
	if (keysym == XK_Escape)
		ft_exit_program(frac);
	if (!ft_strncmp(frac->name, PHOENIX, 8))
	{
		if (keysym == '[')
		{
			frac->delta -= 0.05;
			if (frac->delta < -1.0)
				frac->delta = -1.0;
		}
		if (keysym == ']')
		{
			frac->delta += 0.05;
			if (frac->delta > 1.0)
				frac->delta = 1.0;
		}
	}
	apply_color_shade(keysym, frac);
	apply_zoom_in_out(keysym, frac);
	move_reset_screen(keysym, frac);
	update_iterations(keysym, frac);
	ft_render_fractal(frac);
	return (0);
}
