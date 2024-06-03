/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:59:12 by aattak            #+#    #+#             */
/*   Updated: 2024/06/03 10:11:13 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	go_right(t_data *data)
{
	data->img.x_move += ((MOVE * data->img.x_norm) / (WIDTH - 1));
	data->img.to_render = 1;
}

void	go_left(t_data *data)
{
	data->img.x_move -= ((MOVE * data->img.x_norm) / (WIDTH - 1));
	data->img.to_render = 1;
}

void	go_up(t_data *data)
{
	data->img.y_move += ((MOVE * data->img.y_norm) / (HEIGHT - 1));
	data->img.to_render = 1;
}

void	go_down(t_data *data)
{
	data->img.y_move -= ((MOVE * data->img.y_norm) / (HEIGHT - 1));
	data->img.to_render = 1;
}
