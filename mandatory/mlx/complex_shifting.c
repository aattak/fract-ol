/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_shifting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:24:42 by aattak            #+#    #+#             */
/*   Updated: 2024/05/31 20:04:15 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	shift_complex(int x, int y, t_data *data)
{
	data->img.c.r = scale_x(x, data);
	data->img.c.i = scale_y(y, data);
	data->img.to_re_render = 1;//////////////////////
	//render_fractal(data);
}

void	shift_complex_on(t_data *data)
{
	data->img.shift_state = 1;
}

void	shift_complex_off(t_data *data)
{
	data->img.shift_state = 0;
}
