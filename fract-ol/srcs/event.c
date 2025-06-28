/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:34:41 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/28 16:13:17 by maaugust         ###   ########.fr       */
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
	return (0);
}
