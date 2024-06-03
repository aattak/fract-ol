/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_shifting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:24:42 by aattak            #+#    #+#             */
/*   Updated: 2024/06/03 10:10:25 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	shift_complex(int x, int y, t_data *data)
{
	data->img.c.r = scale_x(x, data);
	data->img.c.i = scale_y(y, data);
	data->img.to_render = 1;
}

void	shift_complex_on(t_data *data)
{
	data->img.shift_state = 1;
}

void	shift_complex_off(t_data *data)
{
	data->img.shift_state = 0;
}
