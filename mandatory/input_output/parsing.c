/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:29:18 by aattak            #+#    #+#             */
/*   Updated: 2024/06/01 17:43:03 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void	two_args_input(char **av, t_data *data)
{
	(void)av;
	if (1/*mandelbrot*/)
		data->fractal = mandelbrot;
	else if (0/*mandelbrot cube*/)
		data->fractal = mandelbrot_cube;
	else if (0/*burning ship*/)
		data->fractal = burning_ship;
	else if (0/*bird of prey*/)
		data->fractal = bird_of_prey;
	else
		invalid_input();
	data->img.shift_complex_feature = 0;
}

static void	four_args_input(char **av, t_data *data)
{
	if (1/*julia*/)
		data->fractal = julia;
	else if (0/*julia cube*/)
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
