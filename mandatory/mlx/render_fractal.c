/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:46:54 by aattak            #+#    #+#             */
/*   Updated: 2024/05/24 21:53:46 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

double	scale_x(int x, t_data *data)
{
	double	r;

	r = ((x * (data->img.x_end - data->img.x_start)) / (WIDTH - 1))
		+ data->img.x_start;
	return (r);
}

double	scale_y(int y, t_data *data)
{
	double	r;

	r = ((y * (data->img.y_start - data->img.y_end)) / (HEIGHT - 1))
		+ data->img.y_start;
	return (r);
}

void	shift_color(t_data *data)
{
	size_t	i;
	int		*pixel;

	i = 0;
	pixel = (int *)data->img.addr;
	while (i < data->img.addr_size)
	{
		if (pixel[i])
			pixel[i] += 0x00050505;
		i++;
	}
	data->img.color += 0x00050505;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.img_ptr, 0, 0);
}

void	draw_fractal_pixel(t_data *data, size_t pos, t_complex p_coord)
{
	int	iterations;
	int	*pixel;

	pixel = (int *)data->img.addr;
	iterations = data->fractal(data, p_coord);
	if (iterations == data->img.iterations)
		pixel[pos] = 0;
	else
		pixel[pos] = iterations * data->img.color;
}

void	render_fractal(t_data *data)
{
	int			x;
	int			y;
	size_t		image_pos;
	t_complex	p_coord;

	x = 0;
	y = 0;
	image_pos = 0;
	while (image_pos < data->img.addr_size)
	{
		p_coord.i = scale_y(y, data);
		while (1)
		{
			////////////ft_putnbr((int)image_pos);///////////////
			///////////ft_putstr(" ");//////////
			p_coord.r = scale_x(x, data);
			draw_fractal_pixel(data, image_pos, p_coord);
			image_pos++;
			x++;
			if ((image_pos % WIDTH != 0))
				break ;
		}
		//////ft_putstr("\n__________inc y____________\n");//////////
		x = 0;
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.img_ptr, 0, 0);
}
