/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:11:45 by aattak            #+#    #+#             */
/*   Updated: 2024/05/22 20:18:56 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_in(t_data *data)
{
	long double	old_scale;

	old_scale = data->img.scale;
	data->img.scale /= ZOOM;
	data->img.x_start = data->img.x_start + (x * (old_scale - data->img.scale));
	data->img.y_start = data->img.y_start + (y * (data->img.scale - old_scale));
	data->fractal(data);
}

void	zoom_out(t_data *data)
{
	long double	old_scale;

	old_scale = data->img.scale;
	data->img.scale *= ZOOM;
	data->img.x_start = data->img.x_start + (x * (old_scale - data->img.scale));
	data->img.y_start = data->img.y_start + (y * (data->img.scale - old_scale));
	data->fractal(data);
}
