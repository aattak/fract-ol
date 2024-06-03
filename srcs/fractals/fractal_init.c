/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:45:38 by aattak            #+#    #+#             */
/*   Updated: 2024/06/03 09:48:38 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

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
	int			i;
	const int	palette[PALETTE_SIZE] = {
		0xF7A654, 0xFC0019, 0x01FF4F, 0xFF01D7, 0x5600CC, 0x00EDF5, 0x5763CF,
		0x99FF94, 0xFEF77C, 0xFFEB00, 0xEF7779, 0xB3498B, 0xFFFF00, 0x39FF14,
		0xFF00FF, 0x00FFFF, 0x3A2170, 0xDB831C, 0xBE2924, 0xDE4959, 0x11808C,
		0xFD00FF, 0xFDFF00, 0x00FF38, 0x00F9FF, 0x3C00FF, 0xE5A7AF, 0xEEBAA7,
		0xF2CEA0, 0xF9E29A, 0xFFF68F, 0x384840, 0x406078, 0xD8C068, 0xC06868,
		0x806878, 0x583840, 0xE0C878, 0x506038, 0x586068, 0x6080A0, 0x446467,
		0xB8C9B0, 0xBEECCC, 0x7A5C6A, 0xBF7738, 0xE8D019, 0x04662E, 0x2C89B3,
		0x331D59, 0xDE282D, 0xE0457B, 0x69B3E7, 0x9EB356, 0xD38235, 0x03257E,
		0x784E90, 0x3F2021, 0xB04A5A, 0xBA5B3F, 0xCB9576, 0x7FA0AC, 0xEEE5D3
	};

	i = 0;
	while (i < PALETTE_SIZE)
	{
		data->img.palette[i] = palette[i];
		i++;
	}
	data->img.color_shift = 0;
	data->img.palette_index = 0;
	data->img.color = palette[0];
	data->generate_color = rgb_adder;
}

void	fractal_init(t_data *data)
{
	data->img.iterations = 30;
	data->img.shift_state = 0;
	data->img.to_render = 1;
	plane_init(data);
	color_init(data);
}
