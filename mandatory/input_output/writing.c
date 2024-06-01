/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:17:35 by aattak            #+#    #+#             */
/*   Updated: 2024/06/01 20:16:12 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	ft_putnbr_fd(int nbr, int fd)
{
	char	c;
	long	nb;

	nb = (long)nbr;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	if (nb > 9)
		ft_putnbr_fd((int)(nb / 10), fd);
	c = (nb % 10) + '0';
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *str, int fd)
{
	write(fd, str, ft_strlen(str));
}

void	how_to_use(void)
{
}

void	invalid_input(void)
{
	ft_putstr_fd("\nUSAGE :\n\n\t-Mandelbrot\t\t: ./fractol mandelbrot\n\n\t"\
		"-Mandelbrot Cube\t: ./fractol mandelbrot_cube\n\n\t-Julia\t\t\t: "\
		"./fractol julia <real part of constant c> "\
		"<imaginary part of constant c>\n\n\t-Julia Cube\t\t: ./fractol "\
		"julia_cube <real part of constant c> <imaginary part of constant c>"\
		"\n\n\t-Burning Ship\t\t: ./fractol burning_ship\n\n\t-Bird of Prey"\
		"\t\t: ./fractol bird_of_prey\n\nN.B: The real and the imaginary parts"\
		" of the constant c must not exceed 9 with a maximum of 10 digits "\
		"of precision.\n\n", 2);
	exit(1);
}
