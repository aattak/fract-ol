/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:29:18 by aattak            #+#    #+#             */
/*   Updated: 2024/06/03 10:26:16 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol_bonus.h"

static void	invalid_input(void)
{
	ft_putstr_fd("\n| USAGE :\n\n\t-Mandelbrot\t\t: ./fractol mandelbrot\n\n\t"\
		"-Mandelbrot Cube\t: ./fractol mandelbrot_cube\n\n\t-Julia\t\t\t: "\
		"./fractol julia <real part of constant c> "\
		"<imaginary part of constant c>\n\n\t-Julia Cube\t\t: ./fractol "\
		"julia_cube <real part of constant c> <imaginary part of constant c>"\
		"\n\n\t-Burning Ship\t\t: ./fractol burning_ship\n\n\t-Bird of Prey"\
		"\t\t: ./fractol bird_of_prey\n\n| N.B: The real and the imaginary "\
		"parts of the constant c must not exceed 9 with a maximum of "\
		"10 digits of precision.\n\n", 2);
	exit(1);
}

static void	two_args_input(char **av, t_data *data)
{
	(void)av;
	if (!ft_strcmp(av[1], "mandelbrot"))
		data->fractal = mandelbrot;
	else if (!ft_strcmp(av[1], "mandelbrot_cube"))
		data->fractal = mandelbrot_cube;
	else if (!ft_strcmp(av[1], "burning_ship"))
		data->fractal = burning_ship;
	else if (!ft_strcmp(av[1], "bird_of_prey"))
		data->fractal = bird_of_prey;
	else
		invalid_input();
	data->img.shift_complex_feature = 0;
}

static void	four_args_input(char **av, t_data *data)
{
	if (!ft_strcmp(av[1], "julia"))
		data->fractal = julia;
	else if (!ft_strcmp(av[1], "julia_cube"))
		data->fractal = julia_cube;
	else
		invalid_input();
	data->img.c.r = ft_atod(av[2]);
	data->img.c.i = ft_atod(av[3]);
	if (data->img.c.r == 1337 || data->img.c.i == 1337)
		invalid_input();
	data->img.shift_complex_feature = 1;
}

void	b_parse_input(int ac, char **av, t_data *data)
{
	if (ac == 1 || ac == 3 || ac > 4)
		invalid_input();
	else if (ac == 2)
		two_args_input(av, data);
	else
		four_args_input(av, data);
}
