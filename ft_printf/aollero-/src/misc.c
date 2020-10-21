/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollero- <aollero@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 14:22:08 by aollero-          #+#    #+#             */
/*   Updated: 2020/08/05 19:34:17 by aollero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/misc.h"

long int	gr(long int a, long int b)
{
	return (a >= b ? a : b);
}

long int	sm(long int a, long int b)
{
	return (a >= b ? b : a);
}

void		ft_wrtptr(char *c, char *str, int size, int flg)
{
	if (flg)
		size = (size <= (int)ft_strlen(str) ? size : (int)ft_strlen(str));
	while (size > 0)
	{
		*c = *str;
		c++;
		str++;
		size--;
	}
}

void		ft_wrtstr_alright(char *to, char *from, int size)
{
	char *startto;
	char *startfr;

	startto = to;
	startfr = from;
	while (*from)
		from++;
	while (*to)
		to++;
	while (size > 0)
	{
		*to = *from;
		to--;
		from--;
		size--;
		if (to == startto || from == startfr)
		{
			*to = *from;
			break ;
		}
	}
}

t_list		*blst(t_list *list, char bool_back)
{
	if (bool_back)
		return (ft_lstlast(list));
	else
		return (list);
}
