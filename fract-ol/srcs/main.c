/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:19:45 by maaugust          #+#    #+#             */
/*   Updated: 2025/07/07 17:18:36 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	print_invalid_input(void)
{
	ft_putendl_fd("*******************************************", STDERR_FILENO);
	ft_putendl_fd("******** Invalid input parameters! ********", STDERR_FILENO);
	ft_putendl_fd("*******************************************", STDERR_FILENO);
	ft_putendl_fd("\nAvailable fractals:", STDERR_FILENO);
	ft_putendl_fd("\tMandelbrot | Julia | Tricorn | Burning Ship | Phoenix",
		STDERR_FILENO);
	ft_putendl_fd("Run one of the following to execute the fractal program:",
		STDERR_FILENO);
	ft_putendl_fd("\tMandelbrot: ./fractol mandelbrot", STDERR_FILENO);
	ft_putendl_fd("\tJulia: ./fractol julia <real> <imag>", STDERR_FILENO);
	ft_putendl_fd("\tTricorn: ./fractol tricorn", STDERR_FILENO);
	ft_putendl_fd("\tBurning Ship: ./fractol 'burning ship'\n", STDERR_FILENO);
	ft_putendl_fd("\tPhoenix: ./fractol phoenix <real> <imag> <delta>",
		STDERR_FILENO);
	ft_putendl_fd("\tPhoenix Variant: ./fractol 'Phoenix Variant' <real> \
<imag> <delta>",
		STDERR_FILENO);
	exit (EXIT_FAILURE);
}

static bool	is_julia_phoenix(t_fractal *frac, int argc, char **argv)
{
	if (argc == 4 && !ft_strncmp(ft_strtoupper(argv[1]), JULIA, 6))
	{
		frac->disp.name = JULIA;
		frac->c.re = ft_atod(argv[2]);
		frac->c.im = ft_atod(argv[3]);
		return (true);
	}
	else if (argc == 5 && (!ft_strncmp(ft_strtoupper(argv[1]), PHOENIX, 8)
			|| !ft_strncmp(ft_strtoupper(argv[1]), PHOENIX_VARIANT, 16)))
	{
		if (!ft_strncmp(ft_strtoupper(argv[1]), PHOENIX, 8))
			frac->disp.name = PHOENIX;
		else
			frac->disp.name = PHOENIX_VARIANT;
		frac->c.re = ft_atod(argv[2]);
		frac->c.im = ft_atod(argv[3]);
		frac->delta = ft_atod(argv[4]);
		if (frac->delta < DELTA_MIN)
			frac->delta = DELTA_MIN;
		else if (frac->delta > DELTA_MAX)
			frac->delta = DELTA_MAX;
		return (true);
	}
	return (false);
}

static void	validate_inputs(t_fractal *frac, int argc, char **argv)
{
	if (is_julia_phoenix(frac, argc, argv))
		return ;
	else if (argc == 2)
	{
		if (!ft_strncmp(ft_strtoupper(argv[1]), MANDELBROT, 11))
			frac->disp.name = MANDELBROT;
		else if (!ft_strncmp(ft_strtoupper(argv[1]), BURNING_SHIP, 13))
			frac->disp.name = BURNING_SHIP;
		else if (!ft_strncmp(ft_strtoupper(argv[1]), TRICORN, 8))
			frac->disp.name = TRICORN;
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
	mlx_key_hook(frac.disp.win, ft_handle_key_event, &frac);
	mlx_hook(frac.disp.win, DestroyNotify, NoEventMask, ft_exit_program, &frac);
	mlx_mouse_hook(frac.disp.win, ft_handle_mouse_event, &frac);
	mlx_loop(frac.disp.mlx);
	return (EXIT_SUCCESS);
}
