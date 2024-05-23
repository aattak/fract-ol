/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:27:26 by aattak            #+#    #+#             */
/*   Updated: 2024/05/22 19:04:50 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mlx_init(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "fract'ol");
	data->img.img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img_ptr, data->img.bpp,
			data->img.line_len, data->img.endian);
	data->img.bypp = data->img.bpp / 8;/// looks useless !!
	data->fractal(data);
	mlx_mouse_hook(data->win_ptr, mouse_hook, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, key_hook, data);
	mlx_hook(data->win_ptr, DestroyNotify, 0, mlx_quit, data);
	mlx_loop_hook(data->mlx_ptr, render, data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			mlx->img.img_ptr, 0, 0);
}

void	mlx_mem_free(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
}

int	mlx_quit(t_data *data)
{
	mlx_loop_end(data->mlx_ptr);
	mlx_loop_hook(data->mlx_ptr, NULL, NULL);
}
