/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:11:45 by aattak            #+#    #+#             */
/*   Updated: 2024/05/27 21:49:56 by aattak           ###   ########.fr       */
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
	render_fractal(data);
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
	render_fractal(data);
}
