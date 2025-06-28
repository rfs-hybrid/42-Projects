/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:19:45 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/28 17:39:55 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	print_invalid_input(void)
{
	ft_putendl_fd("Invalid fractal input paramaters!", STDERR_FILENO);
	exit (EXIT_FAILURE);
}


static void	validate_inputs(t_fractal *frac, int argc, char **argv)
{
	if (argc == 4 && !ft_strncmp(ft_strtoupper(argv[1]), JULIA, 6))
	{
		frac->name = JULIA;
		frac->c.re = ft_atod(argv[2]);
		frac->c.im = ft_atod(argv[3]);
	}
	else if (argc == 2)
	{
		if (!ft_strncmp(ft_strtoupper(argv[1]), MANDELBROT, 11))
			frac->name = MANDELBROT;
		else if (!ft_strncmp(ft_strtoupper(argv[1]), BURNING_SHIP, 13))
			frac->name = BURNING_SHIP;
		else if (!ft_strncmp(ft_strtoupper(argv[1]), TRICORN, 8))
			frac->name = TRICORN;
		else
			print_invalid_input();
	}
	else
		print_invalid_input();
}

int	main(int argc, char **argv)
{	
	t_fractal	frac;

	validate_inputs(&frac, argc, argv);
	ft_init_fractal(&frac);
	ft_render_fractal(&frac);
	mlx_key_hook(frac.win, ft_handle_key_event, &frac);
	mlx_loop(frac.mlx);
	return (0);
}
