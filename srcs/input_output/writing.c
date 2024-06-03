/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:17:35 by aattak            #+#    #+#             */
/*   Updated: 2024/06/03 10:10:18 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

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

static void	htu_part_two(void)
{
	ft_putstr_fd("to increase the iterations and get"\
		" more depth.\t\t|\n|\t\t>'-' key : to decrease the iterations and get"\
		" less depth.\t\t|\n|\t\t\t\t\t\t\t\t\t\t\t|\n+-----------------------"\
		"----------------------------------------------------------------+\n|"\
		"\t\t\t\t\t\t\t\t\t\t\t|\n|\tRestore the initial POV :\t\t\t\t\t\t\t|"\
		"\n|\t\t\t\t\t\t\t\t\t\t\t|\n|\t\t>If you got lost in this infinite un"\
		"iverse dimensions, just\t\t|\n|\t\t hit the backspace key and taraaa!"\
		"! it's your initial dimension.\t|\n|\t\t\t\t\t\t\t\t\t\t\t|\n+-------"\
		"---------------------------------------------------------------------"\
		"-----------+\n|\t\t\t\t\t\t\t\t\t\t\t|\n|\tBecause you are special :"\
		"\t\t\t\t\t\t\t|\n|\t\t\t\t\t\t\t\t\t\t\t|\n|\t\t>I have a special fea"\
		"ture for you, if you like discovering\t\t|\n|\t\t different Julia fra"\
		"ctals smoothly, you only need to press\t\t|\n|\t\t and hold the 'Left"\
		" Shift' key and move your cursor to pick\t\t|\n|\t\t different consta"\
		"nts from the current plane.\t\t\t\t|\n|\t\t\t\t\t\t\t\t\t\t\t|\n+----"\
		"---------------------------------------------------------------------"\
		"--------------+\n|\t\t\t\t\t\t\t\t\t\t\t|\n|\tjust between us!! i did"\
		"n't told ya that u can use the 'escape'\t\t\t|\n|\tkey to quit the pr"\
		"ogram, cuz i don't want u to do so :D\t\t\t\t|\n|\t\t\t\t\t\t\t\t\t\t"\
		"\t|\n+---------------------------------------------------------------"\
		"------------------------+\n\n", 1);
}

void	how_to_use(void)
{
	ft_putstr_fd("\n+---------------------------------------------------------"\
		"------------------------------+\n|\t\t\t\t\t\t\t\t\t\t\t|\n|\tHello a"\
		"nd welcome to Fractals Universe!\t\t\t\t\t\t|\n|\t\t\t\t\t\t\t\t\t\t"\
		"\t|\n|\tTo use this Fractal Visualizer efficiently, I'm providing\t\t"\
		"\t|\n|\tyou this guide that will help you explore the fascinating\t\t"\
		"\t|\n|\tworld of fractals using this interactive program.\t\t\t\t|\n|"\
		"\t\t\t\t\t\t\t\t\t\t\t|\n|\tN.B: Hit 'H' key to show this guide every"\
		"time you need it.\t\t\t|\n|\t\t\t\t\t\t\t\t\t\t\t|\n+----------------"\
		"---------------------------------------------------------------------"\
		"--+\n|\t\t\t\t\t\t\t\t\t\t\t|\n|\tNavigating the interface :\t\t\t\t"\
		"\t\t\t|\n|\t\t\t\t\t\t\t\t\t\t\t|\n|\t\t>Mouse scrolling button : to "\
		"zoom in and zoom out.\t\t\t|\n|\t\t>Arrows keys : to move up, down, r"\
		"ight and left.\t\t\t|\n|\t\t\t\t\t\t\t\t\t\t\t|\n+-------------------"\
		"--------------------------------------------------------------------+"\
		"\n|\t\t\t\t\t\t\t\t\t\t\t|\n|\tChanging thee colors :\t\t\t\t\t\t\t\t"\
		"|\n|\t\t\t\t\t\t\t\t\t\t\t|\n|\t\t>'C' key : to switch the coloring a"\
		"lgorithm.\t\t\t\t|\n|\t\t>'N' key : to pick the next color in the pal"\
		"ette.\t\t\t|\n|\t\t>'P' key : to pick the previous color in the palet"\
		"te\t\t\t|\n|\t\t>Space key : to shift the current color.\t\t\t\t|\n|"\
		"\t\t\t\t\t\t\t\t\t\t\t|\n+-------------------------------------------"\
		"--------------------------------------------+\n|\t\t\t\t\t\t\t\t\t\t"\
		"\t|\n|\tChanging the number of iterations value :\t\t\t\t\t|\n|\t\t\t"\
		"\t\t\t\t\t\t\t\t|\n|\t\t>'+' key : ", 1);
	htu_part_two();
}
