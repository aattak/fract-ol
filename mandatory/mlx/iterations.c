/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:10:22 by aattak            #+#    #+#             */
/*   Updated: 2024/05/22 18:36:03 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	increase_iterations(t_data *data)
{
	data->img.iterations += 5;
	data->img.to_update = 1;
}

void	decrease_iterations(t_data *data)
{
	data->img.iterations -= 5;
	data->img.to_update = 1;
}

int	render(t_data *data)
{
	if (data->to_update)
	{
		data->fractal(data);
		data->to_update = 0;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				mlx->img.img_ptr, 0, 0);
	}
	return (0);
}
