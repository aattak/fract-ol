/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:29:18 by aattak            #+#    #+#             */
/*   Updated: 2024/06/01 11:48:04 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void	two_args_input(char **av, t_data *data)
{
	if (/*mandelbrot*/)
		data->fractal = mandelbrot;
	else if (/*mandelbrot cube*/)
		data->fractal = mandelbrot_cube;
	else if (/*burning ship*/)
		data->fractal = burning_ship;
	else if (/*bird of prey*/)
		data->fractal = bird_of_prey;
	else
		invalid_input();
}

static void	four_args_input(char **av, t_data *data)
{
	if (/*julia*/)
		data->fractal = julia;
	else if (/*julia cube*/)
		data->fractal = julia_cube;
	else
		invalid_input();
	data->img.c.r = ;
	data->img.c.i = ;
	data->img.shift_complex_feature = 1;
}

void	parse_input(int ac, char **av, t_data *data)
{
	data->img.shift_complex_feature = 0;
	if (ac == 1 || ac == 3 || ac > 4)
		invalid_input();
	else if (ac == 2)
	{
	}
	else
	{
	}
}
/*
void	parse_input(int ac, char **av, t_data *data)
{
	(void)ac;
	(void)av;
	data->img.shift_complex_feature = 0;
	if (1)
	{
		data->img.c.r = -0.373;
		data->img.c.i = 0.6;
		data->fractal = julia;
		data->img.shift_complex_feature = 1;
	}
	else
		data->fractal = mandelbrot;
	if (0)
		invalid_input();
}
*/
