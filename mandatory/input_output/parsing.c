/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:29:18 by aattak            #+#    #+#             */
/*   Updated: 2024/06/01 20:26:17 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

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
