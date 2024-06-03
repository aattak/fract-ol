/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:22:54 by aattak            #+#    #+#             */
/*   Updated: 2024/06/03 09:47:44 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	main(int ac, char **av)
{
	t_data		data;

	parse_input(ac, av, &data);
	how_to_use();
	fractal_init(&data);
	if (ft_mlx_init(&data))
		return (1);
	render_fractal(&data);
	mlx_loop(data.mlx_ptr);
	mlx_mem_free(&data);
	return (0);
}
