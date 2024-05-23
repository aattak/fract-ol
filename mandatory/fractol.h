/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:22:41 by aattak            #+#    #+#             */
/*   Updated: 2024/05/22 18:48:05 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <X11/keysym.h>
# include <X11/X.h>

# define WIDTH 800
# define HEIGHT 800

# define MOVE 50
# define ZOOM 10

typedef struct s_complex
{
	long double	r;
	long double	i;
}	t_complex;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;/// need improvement

typedef struct s_img
{
	void		*img_ptr;
	char		*addr;
	int			bpp;
	int			bypp;/// looks useless !!
	int			line_len;
	int			endian;
	int			to_update;
	int			iterations;
	t_complex	c;
	long double	x_start;
	long double	y_start;
	long double	scale;
	t_color		color; /// need improvement
}	t_img;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	void		(*fractal)(struct s_data *);
}	t_data;

#endif
