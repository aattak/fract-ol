/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:52:58 by aattak            #+#    #+#             */
/*   Updated: 2024/05/26 19:01:38 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	mouse_hook(int button, int x, int y, t_data *data)
{
	ft_putstr("mouse hook\n");
	if (button == SCROLL_ZOOM_IN)
		zoom_in(data, x, y);
	else if (button == SCROLL_ZOOM_OUT)
		zoom_out(data, x, y);
	else if (button == MOUSE_LEFT_CLICK && data->img.shift_complex_feature == 1)
	{
		data->img.shift_state = 1;
		cursor_move(x, y, data);
	}
	return (0);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		mlx_quit(data);
	else if (keycode == XK_KP_Add)
		increase_iterations(data);
	else if (keycode == XK_KP_Subtract)
		decrease_iterations(data);
	else if (keycode == XK_Right)
		go_right(data);
	else if (keycode == XK_Left)
		go_left(data);
	else if (keycode == XK_Up)
		go_up(data);
	else if (keycode == XK_Down)
		go_down(data);
	else if (keycode == XK_space)
		shift_color(data);
	else if (keycode == XK_BackSpace)
	{
		plane_init(data);
		render_fractal(data);
	}
	return (0);
}

int	cursor_move(int x, int y, t_data *data)
{
	if (data->img.shift_state)
	{
		data->img.c.r = scale_x(x, data);
		data->img.c.i = scale_y(y, data);
		render_fractal(data);
	}
	return (0);
}

int	shift_on(int button, int x, int y, t_data *data)
{
	if (button == 1)
	{
		data->img.shift_state = 1;
		cursor_move(x, y, data);
	}
	return (0);
}

int	shift_off(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (button == MOUSE_LEFT_CLICK)
		data->img.shift_state = 0;
	return (0);
}
