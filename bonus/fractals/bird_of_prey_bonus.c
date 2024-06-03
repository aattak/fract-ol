/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bird_of_prey_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:56:21 by aattak            #+#    #+#             */
/*   Updated: 2024/06/03 10:22:25 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol_bonus.h"

int	bird_of_prey(t_data *data, t_complex p_coord)
{
	int			i;
	double		r_tmp;
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
		z.r = fabs(z.r * z.r * z.r) - fabs(3 * z.r * z.i * z.i) + c.r;
		z.i = fabs(3 * r_tmp * r_tmp * z.i) - fabs(z.i * z.i * z.i) + c.i;
		i++;
	}
	return (i);
}
