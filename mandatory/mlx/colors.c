/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 17:04:34 by aattak            #+#    #+#             */
/*   Updated: 2024/05/30 18:00:35 by aattak           ###   ########.fr       */
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
	render_fractal(data);
}

void	shift_color(t_data *data)
{
	int		*pixel;
	size_t	i;

	i = 0;
	pixel = (int *)data->img.addr;
	while (i < data->img.addr_size)
	{
		if (pixel[i])
			pixel[i] += COLOR_SHIFT;
		i++;
	}
	data->img.color_shift += COLOR_SHIFT;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.img_ptr, 0, 0);
}

void	shift_palette(t_data *data)
{
	if (data->img.palette_index < PALETTE_SIZE - 1)
		data->img.palette_index++;
	else
		data->img.palette_index = 0;
	data->img.color = data->img.palette[data->img.palette_index];
	render_fractal(data);
}
