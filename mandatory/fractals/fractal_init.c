/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:45:38 by aattak            #+#    #+#             */
/*   Updated: 2024/05/22 19:04:07 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	iterations_init(t_data *data)
{
	data->img.iterations = 30;
}

void	plan_init(t_data *data)
{
	data->img.x_start = -2;
	data->img.y_start = 2;
	data->img.scale = 4 / (WIDTH - 1);
}

void	color_init()
{
}

void	fractal_init(t_data *data)
{
	iterations_init(data);
	plan_init(data);
	color_init(data);
}
