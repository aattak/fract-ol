/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:11:45 by aattak            #+#    #+#             */
/*   Updated: 2024/06/01 09:30:03 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	zoom_in(t_data *data, int x, int y)
{
	double	old_x_norm;
	double	old_y_norm;

	old_x_norm = data->img.x_norm;
	old_y_norm = data->img.y_norm;
	data->img.x_norm /= ZOOM;
	data->img.y_norm /= ZOOM;
	data->img.x_move += (x * (old_x_norm - data->img.x_norm)) / (WIDTH - 1);
	data->img.y_move += (y * (data->img.y_norm - old_y_norm)) / (HEIGHT - 1);
	data->img.to_render = 1;
}

void	zoom_out(t_data *data, int x, int y)
{
	double	old_x_norm;
	double	old_y_norm;

	old_x_norm = data->img.x_norm;
	old_y_norm = data->img.y_norm;
	data->img.x_norm *= ZOOM;
	data->img.y_norm *= ZOOM;
	data->img.x_move += (x * (old_x_norm - data->img.x_norm)) / (WIDTH - 1);
	data->img.y_move += (y * (data->img.y_norm - old_y_norm)) / (HEIGHT - 1);
	data->img.to_render = 1;
}
