/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:10:22 by aattak            #+#    #+#             */
/*   Updated: 2024/06/03 10:10:43 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	increase_iterations(t_data *data)
{
	data->img.iterations += 5;
	if (data->img.iterations > INT_MAX)
		data->img.iterations = 0;
	ft_putnbr_fd(data->img.iterations, 1);
	ft_putstr_fd(" iterations\n", 1);
	data->img.to_render = 1;
}

void	decrease_iterations(t_data *data)
{
	data->img.iterations -= 5;
	if (data->img.iterations < 0)
	{
		data->img.iterations = 0;
		return ;
	}
	ft_putnbr_fd(data->img.iterations, 1);
	ft_putstr_fd(" iterations\n", 1);
	data->img.to_render = 1;
}
