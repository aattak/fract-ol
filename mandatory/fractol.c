/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:22:54 by aattak            #+#    #+#             */
/*   Updated: 2024/05/23 17:53:42 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_data		data;

	parse_input(ac, av, &data);
	fractal_init(&data);
	ft_mlx_init(&data);
	render_fractal(&data);
	mlx_loop(&data.mlx_ptr);
	mlx_mem_free(&data);
	return (0);
}
