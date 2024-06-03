/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_cube_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:52:28 by aattak            #+#    #+#             */
/*   Updated: 2024/06/03 10:26:00 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol_bonus.h"

int	mandelbrot_cube(t_data *data, t_complex p_coord)
{
	int			i;
	double		r_tmp;
	t_complex	z;
	t_complex	c;

	i = 0;
	z.r = 0;
	z.i = 0;
	c = p_coord;
	while (i < data->img.iterations && ((z.r * z.r) + (z.i * z.i)) < 4)
	{
		r_tmp = z.r;
		z.r = (z.r * z.r * z.r) - (3 * z.r * z.i * z.i) + c.r;
		z.i = (3 * r_tmp * r_tmp * z.i) - (z.i * z.i * z.i) + c.i;
		i++;
	}
	return (i);
}
