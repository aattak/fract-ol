/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:52:58 by aattak            #+#    #+#             */
/*   Updated: 2024/05/24 20:42:22 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	mouse_hook(int button, int x, int y, t_data *data)
{
	if (button == SCROLL_ZOOM_IN)
		zoom_in(data, x, y);
	else if (button == SCROLL_ZOOM_OUT)
		zoom_out(data, x, y);
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
//////////////////////
void	ft_printf_p(unsigned long long p, char *base)
{
	char c;///////

	if (p > 15)////
		ft_printf_p(p / 16, base);///////////////
	c = base[p % 16];//////////////
	write(1, &c, 1);///////////
}
/////////////////////
int	shift_on(int button, int x, int y, t_data *data)
{
	if (button == 1)
	{
		data->img.shift_state = 1;
		ft_putstr("\n_____shift on______\n");//////////////////////////
		ft_printf_p((unsigned long long)data, "0123456789abcdef");///////////////
		//ft_putnbr(data->img.shift_state);//////////////////////
		ft_putstr("\n___________\n");////////////////////////////
		cursor_move(x, y, data);
	}
	return (0);
}

int	shift_off(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (button == 1)
		data->img.shift_state = 0;
	return (0);
}
