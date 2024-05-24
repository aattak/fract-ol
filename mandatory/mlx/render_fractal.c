/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:46:54 by aattak            #+#    #+#             */
/*   Updated: 2024/05/24 15:53:56 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	shift_color(t_data *data)
{
	int	i;
	int	*pixel;

	i = 0;
	pixel = data->img.addr;
	while (i < data->img.addr_size)
	{
		if (pixel[i])
			pixel[i] += 0x00050505;
		i++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		mlx->img.img_ptr, 0, 0);
}

void	draw_fractal_pixel(t_data *data, int *pixel, int iterations)
{
	if (iterations == data->img.iterations)
		*pixel = 0;
	else
		*pixel = iterations * data->img.color;
}

void	render_fractal(t_data *data)
{
	int				iterations;
	unsigned long	i;
	int				*pixel;
	t_complex		p_coord;

	i = 0;
	iterations = 0;
	pixel = (int *)data->img.addr;
	p_coord.r = data->img.x_start;
	p_coord.i = data->img.y_start;
	while (i < data->img.addr_size)
	{
		iterations = data->fractal(data, p_coord);
		draw_fractal_pixel(data, &pixel[i], iterations);
		if ((i + 1) % WIDTH == 0)
		{
			p_coord.r = data->img.x_start;
			p_coord.i -= data->img.scale;
		}
		else
			p_coord.r += data->img.scale;
		i++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		mlx->img.img_ptr, 0, 0);
}
