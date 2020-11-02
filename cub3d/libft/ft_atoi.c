/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollero- <aollero@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 17:16:29 by aollero-          #+#    #+#             */
/*   Updated: 2020/09/28 18:05:00 by aollero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *nptr)
{
	int					neg_count;
	int					resul;

	neg_count = 0;
	while (*nptr == '\t' || *nptr == '\n' || *nptr == '\v'
		|| *nptr == '\f' || *nptr == '\r' || *nptr == ' ')
		nptr++;
	if (*nptr == '-')
	{
		neg_count++;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	resul = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		resul = 10 * resul + (*nptr - '0');
		nptr++;
	}
	return ((neg_count == 0 ? 1 : -1) * resul);
}

int		ft_atoi_adv(char **nptr)
{
	int					neg_count;
	int					resul;

	neg_count = 0;
	while (**nptr == '\t' || **nptr == '\n' || **nptr == '\v'
		|| **nptr == '\f' || **nptr == '\r' || **nptr == ' ')
		(*nptr)++;
	if (**nptr == '-')
	{
		neg_count++;
		(*nptr)++;
	}
	else if (**nptr == '+')
		(*nptr)++;
	resul = 0;
	while (**nptr >= '0' && **nptr <= '9')
	{
		resul = 10 * resul + (**nptr - '0');
		(*nptr)++;
	}
	return ((neg_count == 0 ? 1 : -1) * resul);
}
