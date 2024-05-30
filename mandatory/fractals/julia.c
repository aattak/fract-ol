/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:48:14 by aattak            #+#    #+#             */
/*   Updated: 2024/05/30 17:07:11 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	julia(t_data *data, t_complex p_coord)
{
	int			i;
	double	r_tmp;
	t_complex	z;
	t_complex	c;

	i = 0;
	z = p_coord;
	c = data->img.c;
	while (i < data->img.iterations && ((z.r * z.r) + (z.i * z.i)) < 4)
	{
		r_tmp = z.r;
		z.r = (z.r * z.r) - (z.i * z.i) + c.r;
		z.i = (2 * r_tmp * z.i) + c.i;
	//	z.r = (z.r * z.r * z.r) - (3 * z.r * z.i * z.i) + c.r;
	//	z.i = (3 * z.r * z.r * z.i) - (z.i * z.i * z.i) + c.i;
		i++;
	}
	return (i);
}
// (a + bi)^3 + cr + ci = a^3 + (b*i)^3 + 3*(a^2)*b*i + 3*a*(b*i)^2 + cr + ci
//						= a^3 - i(b^3) + i3*(a^2)*b - 3*a*(b^2) + cr + ci
//						= (a^3 - 3ab^2 + cr) + i(3a^2b - b^3 + ci)

// zr = (zr * zr * zr) - (3 * zr * zi * zi) + cr
// zi = (3 * zr * zr * zi) - (zi * zi * zi) + ci
