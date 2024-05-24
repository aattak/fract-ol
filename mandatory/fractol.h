/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:22:41 by aattak            #+#    #+#             */
/*   Updated: 2024/05/24 21:46:30 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>
# include <X11/keysym.h>
# include <X11/X.h>

# define WIDTH 600
# define HEIGHT 600

# define MOVE 50
# define ZOOM 10

# define SCROLL_ZOOM_IN 4
# define SCROLL_ZOOM_OUT 5

# define MOUSE_LEFT_BUTTON 1

typedef struct s_complex
{
	double	r;
	double	i;
}	t_complex;

typedef struct s_img
{
	void		*img_ptr;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	int			to_re_render;
	int			iterations;
	int			shift_state;
	int			shift_complex_feature;
	int			color;
	size_t		addr_size;
	double	x_start;
	double	x_end;
	double	y_start;
	double	y_end;
	double	scale;////////////////// to delete
	t_complex	z;
	t_complex	c;
}	t_img;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	int			(*fractal)(struct s_data *, t_complex);
}	t_data;


//////////////////////////////////////////
void	ft_printf_p(unsigned long long p, char *base); //////////////////
////////////////////////////////////////////

void	shift_state_init(t_data *data);
void	iterations_init(t_data *data);
void	plane_init(t_data *data);
void	color_init(t_data *data);
void	fractal_init(t_data *data);
int		julia(t_data *data, t_complex p_coord);
int		mandelbrot(t_data *data, t_complex p_coord);
void	parse_input(int ac, char **av, t_data *data);
size_t	ft_strlen(char *str);
void	ft_putnbr(int nbr);
void	ft_putstr(char *str);
void	increase_iterations(t_data *data);
void	decrease_iterations(t_data *data);
int		update_iterations(t_data *data);
void	ft_mlx_init(t_data *data);
void	mlx_mem_free(t_data *data);
int		mlx_quit(t_data *data);
int		mouse_hook(int button, int x, int y, t_data *data);
int		key_hook(int keycode, t_data *data);
int		cursor_move(int x, int y, t_data *data);
int		shift_on(int button, int x, int y, t_data *data);
int		shift_off(int button, int x, int y, t_data *data);
void	go_right(t_data *data);
void	go_left(t_data *data);
void	go_up(t_data *data);
void	go_down(t_data *data);
void	shift_color(t_data *data);
void	draw_fractal_pixel(t_data *data, size_t pos, t_complex p_coord);
void	render_fractal(t_data *data);
void	zoom_in(t_data *data, int x, int y);
void	zoom_out(t_data *data, int x, int y);
double	scale_x(int x, t_data *data);
double	scale_y(int y, t_data *data);

#endif
