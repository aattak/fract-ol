/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:29:18 by aattak            #+#    #+#             */
/*   Updated: 2024/05/24 18:31:38 by aattak           ###   ########.fr       */
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
	ft_putstr("\n____parse input_______\n");//////////////////
	ft_printf_p((unsigned long long)data, "0123456789abcdef");/////////////////////
	//ft_putnbr(data->img.shift_state);//////////////////////////////
	ft_putstr("\n___________\n");/////////////////////////
	data->img.shift_complex_feature = 0;
	if (0/*julia*/)
	{
		data->img.c.r = -0.373;
		data->img.c.i = 0.6;
		data->fractal = julia;
		data->img.shift_complex_feature = 1;
	}
	else if (1/*mandelbrot*/)
		data->fractal = mandelbrot;
	if (0)
		parsing_error();/// to delete
}
