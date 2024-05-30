/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:45:38 by aattak            #+#    #+#             */
/*   Updated: 2024/05/30 18:14:50 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	shift_state_init(t_data *data)
{
	data->img.shift_state = 0;
}

void	iterations_init(t_data *data)
{
	data->img.iterations = 30;
}

void	plane_init(t_data *data)
{
	data->img.x_start = (double)X_START;
	data->img.x_norm = (double)X_END - data->img.x_start;
	data->img.y_norm = (data->img.x_norm * (HEIGHT - 1)) / (WIDTH - 1);
	data->img.y_start = (data->img.y_norm / 2);
	data->img.x_move = 0;
	data->img.y_move = 0;
}

void	color_init(t_data *data)
{
	/// this declaration here is invlid because the palette got lost after
	/// the function got terminated. must fix it.
	const int	palette[PALETTE_SIZE] = {
		0xFF0000, 0xFF7F00, 0xFFFF00, 0x7FFF00,
		0x00FF00, 0x00FF7F, 0x00FFFF, 0x007FFF,
		0x0000FF, 0x7F00FF, 0xFF00FF, 0xFF007F,
		0xFF1493, 0xFFD700, 0x8A2BE2, 0x00FA9A
	};
	data->img.color_shift = 0;
	data->img.color = palette[14];
	data->img.palette_index = 0;
	data->img.palette = palette;
}

void	fractal_init(t_data *data)
{
	shift_state_init(data);
	iterations_init(data);
	plane_init(data);
	color_init(data);
}
