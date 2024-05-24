/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:29:18 by aattak            #+#    #+#             */
/*   Updated: 2024/05/24 11:22:45 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void	parsing_error(void)
{
}

void	parse_input(int ac, char **av, t_data *data)
{
	data->img.shift_complex_feature = 0;
	if (/*julia*/)
	{
		data->c.r = ;
		data->c.i = ;
		data->fractal = julia;
		data->img.shift_complex_feature = 1;
	}
	else if (/*mandelbrot*/)
		data->fractal = mandelbrot;
}
