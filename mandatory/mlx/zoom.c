/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:11:45 by aattak            #+#    #+#             */
/*   Updated: 2024/05/23 18:21:48 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	zoom_in(t_data *data, int x, int y)
{
	long double	old_scale;

	old_scale = data->img.scale;
	data->img.scale /= ZOOM;
	data->img.x_start = data->img.x_start + (x * (old_scale - data->img.scale));
	data->img.y_start = data->img.y_start + (y * (data->img.scale - old_scale));
	render_fractal(data);
}

void	zoom_out(t_data *data, int x, int y)
{
	long double	old_scale;

	old_scale = data->img.scale;
	data->img.scale *= ZOOM;
	data->img.x_start = data->img.x_start + (x * (old_scale - data->img.scale));
	data->img.y_start = data->img.y_start + (y * (data->img.scale - old_scale));
	render_fractal(data);
}
