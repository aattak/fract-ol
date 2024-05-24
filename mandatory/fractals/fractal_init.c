/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:45:38 by aattak            #+#    #+#             */
/*   Updated: 2024/05/24 20:45:04 by aattak           ###   ########.fr       */
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
	data->img.x_start = -2;
	data->img.x_end = 2;
	data->img.y_start = 2;
	data->img.y_end = -2;
}

void	color_init(t_data *data)
{
	data->img.color = 0x0005142B;
}

void	fractal_init(t_data *data)
{
	shift_state_init(data);
	iterations_init(data);
	plane_init(data);
	color_init(data);
}
