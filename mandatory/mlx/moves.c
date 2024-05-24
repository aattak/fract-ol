/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:59:12 by aattak            #+#    #+#             */
/*   Updated: 2024/05/24 20:51:53 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	go_right(t_data *data)
{
	data->img.x_start = scale_x(MOVE, data);
	render_fractal(data);
}

void	go_left(t_data *data)
{
	data->img.x_start = scale_x(-MOVE, data);
	render_fractal(data);
}

void	go_up(t_data *data)
{
	data->img.y_start = scale_y(MOVE, data);
	render_fractal(data);
}

void	go_down(t_data *data)
{
	data->img.y_start = scale_y(-MOVE, data);
	render_fractal(data);
}
