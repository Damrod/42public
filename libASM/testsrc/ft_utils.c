/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollero- <aollero@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 22:05:01 by aollero-          #+#    #+#             */
/*   Updated: 2020/10/31 01:54:29 by aollero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_putnbr(int nbr)
{
	if (nbr < 0)
	{
		write(1, "-", 1);
		ft_putnbr(-nbr);
		return ;
	}
	if (nbr > 9)
		ft_putnbr(nbr / 10);
	write(1, &"0123456789"[nbr % 10], 1);
}

int		intpower(int a, unsigned int b)
{
	if (b == 0)
		return (1);
	else if (b == 1)
		return (a);
	else
		return (a * intpower(a, b - 1));
}

int		ft_atoi(char *str)
{
	int					neg_count;
	int					resul;

	neg_count = 0;
	while (*str == '\t' || *str == '\n' || *str == '\v'
			|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg_count++;
		str++;
	}
	resul = 0;
	while (*str >= '0' && *str <= '9')
	{
		resul = 10 * resul + (*str - '0');
		str++;
	}
	return (intpower(-1, neg_count) * resul);
}
