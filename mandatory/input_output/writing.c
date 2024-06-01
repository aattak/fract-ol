/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:17:35 by aattak            #+#    #+#             */
/*   Updated: 2024/06/01 12:09:43 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
	{
		len++;
		if (!len)
			return (--len);
	}
	return (len);
}

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

void	invalid_input(void)
{
	ft_putstr_fd("USAGE :\n\t-Mandelbrot : ./fractol mandelbrot\n\t\
		-Mandelbrot Cube : ./fractol mandelbrot_cube\n\t-Julia : ./fractol \
		julia <real part of constant c> <imaginary part of constant c>\n\t\
		-Julia Cube : ./fractol julia_cube <real part of constant c> \
		<imaginary part of constant c>\n\t-Burning Ship : ./fractol \
		burning_ship\n\t-Bird of Prey : ./fractol bird_of_prey\n", 2);
	exit(1);
}
