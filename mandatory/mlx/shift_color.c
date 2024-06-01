/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 17:04:34 by aattak            #+#    #+#             */
/*   Updated: 2024/06/01 09:29:14 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	shift_color(t_data *data)
{
	int		*pixel;
	size_t	i;

	i = -1;
	pixel = (int *)data->img.addr;
	if (data->img.color_shift + COLOR_SHIFT <= 0x00FFFFFF)
	{
		while (++i < data->img.addr_size)
		{
			if (pixel[i])
				pixel[i] += COLOR_SHIFT;
		}
		data->img.color_shift += COLOR_SHIFT;
	}
	else
	{
		while (++i < data->img.addr_size)
		{
			if (pixel[i])
				pixel[i] -= data->img.color_shift;
		}
		data->img.color_shift = 0;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.img_ptr, 0, 0);
}

void	shift_palette_up(t_data *data)
{
	if (data->img.palette_index < PALETTE_SIZE - 1)
		data->img.palette_index++;
	else
		data->img.palette_index = 0;
	data->img.color_shift = 0;
	data->img.color = data->img.palette[data->img.palette_index];
	data->img.to_render = 1;
}

void	shift_palette_down(t_data *data)
{
	if (data->img.palette_index > 0)
		data->img.palette_index--;
	else
		data->img.palette_index = PALETTE_SIZE - 1;
	data->img.color_shift = 0;
	data->img.color = data->img.palette[data->img.palette_index];
	data->img.to_render = 1;
}
