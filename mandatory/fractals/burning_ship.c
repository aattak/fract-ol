/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:57:28 by aattak            #+#    #+#             */
/*   Updated: 2024/05/30 17:08:08 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	burning_ship(t_data *data, t_complex p_coord)
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
		z.r = fabs(z.r * z.r) - fabs(z.i * z.i) + c.r;
		z.i = fabs(2 * r_tmp * z.i) + c.i;
		i++;
	}
	return (i);
}
