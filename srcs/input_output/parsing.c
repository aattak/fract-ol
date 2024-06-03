/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:29:18 by aattak            #+#    #+#             */
/*   Updated: 2024/06/03 11:39:38 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

static void	invalid_input(void)
{
	ft_putstr_fd("\n| USAGE :\n\n\t-Mandelbrot\t\t: ./fractol mandelbrot\n\n\t"\
		"-Julia\t\t\t: ./fractol julia <real part of constant c> "\
		"<imaginary part of constant c>\n\n| N.B: The real and the imaginary"\
		" parts of the constant c must not exceed 9 with a "\
		"maximum of 10 digits of precision.\n\n", 2);
	exit(1);
}

static void	two_args_input(char **av, t_data *data)
{
	(void)av;
	if (!ft_strcmp(av[1], "mandelbrot"))
		data->fractal = mandelbrot;
	else
		invalid_input();
	data->img.shift_complex_feature = 0;
}

static void	four_args_input(char **av, t_data *data)
{
	if (!ft_strcmp(av[1], "julia"))
		data->fractal = julia;
	else
		invalid_input();
	data->img.c.r = ft_atod(av[2]);
	data->img.c.i = ft_atod(av[3]);
	if (data->img.c.r == 1337 || data->img.c.i == 1337)
		invalid_input();
	data->img.shift_complex_feature = 1;
}

void	parse_input(int ac, char **av, t_data *data)
{
	if (ac == 1 || ac == 3 || ac > 4)
		invalid_input();
	else if (ac == 2)
		two_args_input(av, data);
	else
		four_args_input(av, data);
}
