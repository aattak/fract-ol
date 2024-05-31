/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:48:51 by aattak            #+#    #+#             */
/*   Updated: 2024/05/31 10:26:13 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	mandelbrot(t_data *data, t_complex p_coord)
{
	int			i;
	double	r_tmp;
	t_complex	z;
	t_complex	c;

	i = 0;
	z.r = 0;
	z.i = 0;
	c = p_coord;
	c.i *= -1;
	while (i < data->img.iterations && ((z.r * z.r) + (z.i * z.i)) < 4)
	{
		r_tmp = z.r;
	//	z.r = fabs(z.r * z.r) - fabs(z.i * z.i) + c.r;
	//	z.i = fabs(2 * r_tmp * z.i) + c.i;
		z.r = fabs(z.r * z.r * z.r) - fabs(3 * z.r * z.i * z.i) + c.r;
		z.i = fabs(3 * r_tmp * r_tmp * z.i) - fabs(z.i * z.i * z.i) + c.i;
		i++;
	}
	return (i);
}
