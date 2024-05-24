/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:27:26 by aattak            #+#    #+#             */
/*   Updated: 2024/05/24 17:39:16 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	ft_mlx_init(t_data *data)
{
		ft_putstr("\n_____mlx init______\n");//////////////////////////
		ft_printf_p((unsigned long long)data, "0123456789abcdef");///////////////
		//ft_putnbr(data->img.shift_state);//////////////////////
		ft_putstr("\n___________\n");////////////////////////////
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "fract'ol");
	data->img.img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img_ptr, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
	data->img.addr_size = (WIDTH * HEIGHT);
	mlx_mouse_hook(data->win_ptr, mouse_hook, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, key_hook, data);
	mlx_hook(data->win_ptr, DestroyNotify, 0, mlx_quit, data);
	mlx_loop_hook(data->mlx_ptr, update_iterations, data);
	if (data->img.shift_complex_feature == 1)
	{
		mlx_hook(data->win_ptr, ButtonPress, ButtonPressMask, shift_on, data);
		mlx_hook(data->win_ptr, ButtonRelease,
			ButtonReleaseMask, shift_off, data);
		mlx_hook(data->win_ptr, MotionNotify,
			PointerMotionMask, cursor_move, data);
	}
}

void	mlx_mem_free(t_data *data)
{
		ft_putstr("\n_____mlx mem free______\n");//////////////////////////
		ft_printf_p((unsigned long long)data, "0123456789abcdef");///////////////
		//ft_putnbr(data->img.shift_state);//////////////////////
		ft_putstr("\n___________\n");////////////////////////////
	mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
}

int	mlx_quit(t_data *data)
{
		ft_putstr("\n_____mlx quit______\n");//////////////////////////
		ft_printf_p((unsigned long long)data, "0123456789abcdef");///////////////
		//ft_putnbr(data->img.shift_state);//////////////////////
		ft_putstr("\n___________\n");////////////////////////////
	mlx_loop_end(data->mlx_ptr);
	mlx_loop_hook(data->mlx_ptr, NULL, NULL);
	return (0);
}
