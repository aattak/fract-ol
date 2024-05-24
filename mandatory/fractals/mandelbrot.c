/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:48:51 by aattak            #+#    #+#             */
/*   Updated: 2024/05/24 14:27:42 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	mandelbrot(t_data *data, t_complex p_coord)
{
	int			i;
	long double	r_tmp;
	t_complex	z;
	t_complex	c;

	i = 0;
	z.r = 0;
	z.i = 0;
	c = p_coord;
	while (i < data->img.iterations && ((z.r * z.r) + (z.i * z.i)) < 4)
	{
		r_tmp = z.r;
		z.r = (z.r * z.r) - (z.i * z.i) + c.r;
		z.i = (2 * r_tmp * z.i) + c.i;
		i++;
	}
	return (i);
}
