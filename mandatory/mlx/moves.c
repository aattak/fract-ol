/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:59:12 by aattak            #+#    #+#             */
/*   Updated: 2024/05/22 20:03:00 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	go_right(t_data *data)
{
	data->img.x_start = data->img.x_start + (MOVE * data->img.scale);
	data->fractal(data);
}

void	go_left(t_data *data)
{
	data->img.x_start = data->img.x_start - (MOVE * data->img.scale);
	data->fractal(data);
}

void	go_up(t_data *data)
{
	data->img.y_start = data->img.y_start + (MOVE * data->img.scale);
	data->fractal(data);
}

void	go_down(t_data *data)
{
	data->img.y_start = data->img.y_start - (MOVE * data->img.scale);
	data->fractal(data);
}
