/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:34:41 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/28 20:28:33 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_handle_key_event(int keysym, t_fractal *frac)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_image(frac->mlx, frac->data.img);
		mlx_destroy_window(frac->mlx, frac->win);
		mlx_destroy_display(frac->mlx);
		free(frac->mlx);
		exit(1);
	}
	if (keysym == XK_p && !frac->is_gray)
	{
		frac->palette_idx = (frac->palette_idx + 1) % frac->n_palettes;
		ft_render_fractal(frac);
	}
	if (keysym == XK_g)
	{
		frac->is_gray = !frac->is_gray;
		ft_render_fractal(frac);
	}
	return (0);
}
