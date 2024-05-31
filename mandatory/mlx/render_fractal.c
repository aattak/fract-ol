/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:46:54 by aattak            #+#    #+#             */
/*   Updated: 2024/05/31 20:47:24 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

double	scale_x(int x, t_data *data)
{
	double	r;

	r = data->img.x_start + ((x * data->img.x_norm) / (WIDTH - 1))
		+ data->img.x_move;
	return (r);
}

double	scale_y(int y, t_data *data)
{
	double	i;

	i = data->img.y_start - ((y * data->img.y_norm) / (HEIGHT - 1))
		+ data->img.y_move;
	return (i);
}

void	draw_fractal_pixel(t_data *data, t_complex p_coord, int x, int y)
{
	int		iterations;
	char	*pixel;
	size_t	index;

	index = ((y * WIDTH) + x) * (data->img.bpp / 8);
	pixel = data->img.addr + index;
	iterations = data->fractal(data, p_coord);
	if (iterations == data->img.iterations)
		*(int *)pixel = 0;
	else
		*(int *)pixel = data->generate_color(*data, iterations);
}

int	render_fractal(t_data *data)
{
	int			x;
	int			y;
	t_complex	p_coord;

	if (data->img.to_re_render)
	{
		x = 0;
		y = 0;
		data->img.to_re_render = 0;
		while (y < HEIGHT)
		{
			p_coord.i = scale_y(y, data);
			while (x < WIDTH)
			{
				p_coord.r = scale_x(x, data);
				draw_fractal_pixel(data, p_coord, x, y);
				x++;
			}
			x = 0;
			y++;
		}
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img.img_ptr, 0, 0);
	}
	return (0);
}
