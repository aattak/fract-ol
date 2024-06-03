/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:22:41 by aattak            #+#    #+#             */
/*   Updated: 2024/06/03 09:46:48 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include "fractol.h"

// Bonus fractals functions
int		mandelbrot_cube(t_data *data, t_complex p_coord);
int		julia_cube(t_data *data, t_complex p_coord);
int		burning_ship(t_data *data, t_complex p_coord);
int		bird_of_prey(t_data *data, t_complex p_coord);

// Bonus Input-Output functions
void	b_parse_input(int ac, char **av, t_data *data);

#endif
