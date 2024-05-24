/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:22:41 by aattak            #+#    #+#             */
/*   Updated: 2024/05/24 14:42:05 by aattak           ###   ########.fr       */
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

# define WIDTH 800
# define HEIGHT 800

# define MOVE 50
# define ZOOM 10

# define SCROLL_ZOOM_IN 4
# define SCROLL_ZOOM_OUT 5

# define MOUSE_LEFT_BUTTON 1

typedef struct s_complex
{
	long double	r;
	long double	i;
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
	long double	x_start;
	long double	y_start;
	long double	scale;
	t_complex	z;
	t_complex	c;
}	t_img;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	int			(*fractal)(struct s_data, t_complex);
}	t_data;

#endif
