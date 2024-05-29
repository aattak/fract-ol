/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:46:54 by aattak            #+#    #+#             */
/*   Updated: 2024/05/29 08:00:11 by aattak           ###   ########.fr       */
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
	//double	magnitude;
	//t_complex	z;

	index = ((y * WIDTH) + x) * (data->img.bpp / 8);
	pixel = data->img.addr + index;
	//z = data->img.z;
	//magnitude = sqrt((z.r * z.r) + (z.i * z.i));
	iterations = data->fractal(data, p_coord);// + 1 - log(log2(magnitude));
	if (iterations == data->img.iterations)
		*(int *)pixel = 0;
	else
		*(int *)pixel = (iterations * data->img.color) + data->img.color_shift;
}

void	render_fractal(t_data *data)
{
	int			x;
	int			y;
	t_complex	p_coord;

	x = 0;
	y = 0;
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
