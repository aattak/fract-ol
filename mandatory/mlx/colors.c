/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 17:04:34 by aattak            #+#    #+#             */
/*   Updated: 2024/05/29 08:08:22 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	shift_color_up(t_data *data, int *pixel)
{
	size_t	i;

	i = 0;
	while (i < data->img.addr_size)
	{
		if (pixel[i])
			pixel[i] += COLOR_SHIFT;
		i++;
	}
	data->img.color_shift += COLOR_SHIFT;
}

void	shift_color_down(t_data *data, int *pixel)
{
	size_t	i;

	i = 0;
	while (i < data->img.addr_size)
	{
		if (pixel[i])
			pixel[i] += COLOR_SHIFT;
		i++;
	}
	data->img.color_shift += COLOR_SHIFT;
}

void	shift_color(t_data *data)
{
	int		*pixel;

	pixel = (int *)data->img.addr;
	shift_color_up(data, pixel);
//	if (data->img.color * COLOR_SHIFT > 0 && data->img.color * COLOR_SHIFT < 0x00FFFFFF)
//		shift_color_up(data, pixel);
//	else
//	{
//		if (data->img.color * COLOR_SHIFT > 0x00FFFFFF)
//			data->img.color *= -1;
//		if (data->img.color * COLOR_SHIFT != 0)
//			shift_color_down(data, pixel);
//		else
//			data->img.color = COLOR;
//	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.img_ptr, 0, 0);
	ft_putnbr(data->img.color);
	write(1, "\n", 1);
}
