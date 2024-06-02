/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:52:58 by aattak            #+#    #+#             */
/*   Updated: 2024/06/02 08:18:52 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	key_press_hook(int keycode, t_data *data)
{
	int	x;
	int	y;

	if (keycode == XK_Escape)
		mlx_quit(data);
	else if (keycode == XK_KP_Add || keycode == XK_equal)
		increase_iterations(data);
	else if (keycode == XK_KP_Subtract || keycode == XK_minus)
		decrease_iterations(data);
	else if (keycode == XK_space)
		shift_color(data);
	else if (keycode == XK_Shift_L && data->img.shift_complex_feature == 1)
	{
		shift_complex_on(data);
		mlx_mouse_get_pos(data->mlx_ptr, data->win_ptr, &x, &y);
		shift_complex(x, y, data);
	}
	return (0);
}

int	key_release_hook(int keycode, t_data *data)
{
	if (keycode == XK_Right)
		go_right(data);
	else if (keycode == XK_Left)
		go_left(data);
	else if (keycode == XK_Up)
		go_up(data);
	else if (keycode == XK_Down)
		go_down(data);
	else if (keycode == XK_n)
		shift_palette_up(data);
	else if (keycode == XK_p)
		shift_palette_down(data);
	else if (keycode == XK_c)
		switch_color_generator(data);
	else if (keycode == XK_h)
		how_to_use();
	else if (keycode == XK_Shift_L && data->img.shift_complex_feature == 1)
		shift_complex_off(data);
	else if (keycode == XK_BackSpace)
	{
		plane_init(data);
		data->img.to_render = 1;
	}
	return (0);
}

int	mouse_press_hook(int button, int x, int y, t_data *data)
{
	if (button == SCROLL_ZOOM_IN)
		zoom_in(data, x, y);
	else if (button == SCROLL_ZOOM_OUT)
		zoom_out(data, x, y);
	return (0);
}

int	cursor_move_hook(int x, int y, t_data *data)
{
	if (data->img.shift_state)
		shift_complex(x, y, data);
	return (0);
}
