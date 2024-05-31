/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:10:22 by aattak            #+#    #+#             */
/*   Updated: 2024/05/31 20:47:36 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	increase_iterations(t_data *data)
{
	data->img.iterations += 5;
	if (data->img.iterations > INT_MAX)
		data->img.iterations = 0;
	ft_putnbr(data->img.iterations);
	ft_putstr(" iterations\n");
	data->img.to_re_render = 1;
}

void	decrease_iterations(t_data *data)
{
	data->img.iterations -= 5;
	if (data->img.iterations < 0)
	{
		data->img.iterations = 0;
		return ;
	}
	ft_putnbr(data->img.iterations);
	ft_putstr(" iterations\n");
	data->img.to_re_render = 1;
}
