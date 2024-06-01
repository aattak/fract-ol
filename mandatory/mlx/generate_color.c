/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 09:15:35 by aattak            #+#    #+#             */
/*   Updated: 2024/06/01 09:24:59 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	rgb_adder(t_data data, int iterations)
{
	int	color;

	iterations = iterations % 255;
	color = data.img.color + (iterations << 16 | iterations << 8 | iterations)
		+ data.img.color_shift;
	return (color);
}

int	rgb_multiplier(t_data data, int iterations)
{
	int	color;

	color = (data.img.color * iterations) + data.img.color_shift;
	return (color);
}

void	switch_color_generator(t_data *data)
{
	if (data->generate_color == rgb_adder)
		data->generate_color = rgb_multiplier;
	else
		data->generate_color = rgb_adder;
	data->img.to_render = 1;
}
