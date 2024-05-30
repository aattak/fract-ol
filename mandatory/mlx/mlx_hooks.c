/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:52:58 by aattak            #+#    #+#             */
/*   Updated: 2024/05/30 17:48:19 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	key_press_hook(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		mlx_quit(data);
	else if (keycode == XK_KP_Add)
		increase_iterations(data);
	else if (keycode == XK_KP_Subtract)
		decrease_iterations(data);
	else if (keycode == XK_space)
		shift_color(data);
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
	else if (keycode == XK_p)
		shift_palette(data);
	else if (keycode == XK_c)
		switch_color_generator(data);
	else if (keycode == XK_BackSpace)
	{
		plane_init(data);
		render_fractal(data);
	}
	return (0);
}

int	mouse_press_hook(int button, int x, int y, t_data *data)
{
	if (button == SCROLL_ZOOM_IN)
		zoom_in(data, x, y);
	else if (button == SCROLL_ZOOM_OUT)
		zoom_out(data, x, y);
	else if (button == MOUSE_LEFT_CLICK && data->img.shift_complex_feature == 1)
		shift_complex_on(x, y, data);
	return (0);
}

int	mouse_release_hook(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (button == MOUSE_LEFT_CLICK && data->img.shift_complex_feature == 1)
		shift_complex_off(data);
	return (0);
}

int	cursor_move_hook(int x, int y, t_data *data)
{
	if (data->img.shift_state)
	{
		data->img.c.r = scale_x(x, data);
		data->img.c.i = scale_y(y, data);
		render_fractal(data);
	}
	return (0);
}
