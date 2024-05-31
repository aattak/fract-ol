/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:29:18 by aattak            #+#    #+#             */
/*   Updated: 2024/05/31 10:30:09 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void	parsing_error(void)
{
	ft_putstr("error");
}	

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


	if (1)
		data->generate_color = rgb_adder;
	else
		data->generate_color = rgb_multiplier;

	if (0)
		parsing_error();
}
