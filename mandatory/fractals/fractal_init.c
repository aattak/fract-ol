/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:45:38 by aattak            #+#    #+#             */
/*   Updated: 2024/05/26 16:57:54 by aattak           ###   ########.fr       */
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
	data->img.color = COLOR;
}

void	fractal_init(t_data *data)
{
	shift_state_init(data);
	iterations_init(data);
	plane_init(data);
	color_init(data);
}
