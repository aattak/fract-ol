/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 17:11:15 by aattak            #+#    #+#             */
/*   Updated: 2024/06/03 10:10:12 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

static void	skip_whitespaces(char *str, int *i)
{
	while ((str[*i] >= 9 && str[*i] <= 13) || str[*i] == 32)
		(*i)++;
}

static int	check_sign(char *str, int *i)
{
	int	sign;

	sign = 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

double	ft_atod(char *str)
{
	int		i;
	int		sign;
	double	nbr;
	double	precision;

	i = 0;
	precision = 0.1;
	nbr = 0;
	skip_whitespaces(str, &i);
	sign = check_sign(str, &i);
	while (str[i] >= '0' && str[i] <= '9' && nbr == 0)
		nbr = (nbr * 10) + str[i++] - '0';
	if (str[i] == '.')
	{
		i++;
		while (str[i] >= '0' && str[i] <= '9' && precision >= 0.0000000001)
		{
			nbr = nbr + ((str[i++] - '0') * precision);
			precision /= 10;
		}
	}
	skip_whitespaces(str, &i);
	if (str[i])
		return (1337);
	return (nbr * sign);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	diff;

	i = 0;
	diff = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
		{
			diff = s1[i] - s2[i];
			return (diff);
		}
		i++;
	}
	return (diff);
}

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
