/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:27:26 by aattak            #+#    #+#             */
/*   Updated: 2024/06/02 10:59:28 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static int	win_alloc_failure(t_data *data)
{
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	return (1);
}

static int	img_alloc_failure(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	return (1);
}

int	ft_mlx_init(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (1);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "fract'ol");
	if (data->win_ptr == NULL)
		return (win_alloc_failure(data));
	data->img.img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	if (data->img.img_ptr == NULL)
		return (img_alloc_failure(data));
	data->img.addr = mlx_get_data_addr(data->img.img_ptr, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
	data->img.addr_size = (WIDTH * HEIGHT);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, key_press_hook, data);
	mlx_hook(data->win_ptr, KeyRelease, KeyReleaseMask, key_release_hook, data);
	mlx_hook(data->win_ptr, ButtonPress,
		ButtonPressMask, mouse_press_hook, data);
	mlx_hook(data->win_ptr, MotionNotify,
		PointerMotionMask, cursor_move_hook, data);
	mlx_hook(data->win_ptr, DestroyNotify, 0, mlx_quit, data);
	mlx_loop_hook(data->mlx_ptr, render_fractal, data);
	return (0);
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
	ft_putstr_fd("\n+------------------------------------------+\n|  "\
		"Wish you enjoyed it, have a good day!!  "\
		"|\n+------------------------------------------+\n\n", 1);
	return (0);
}
