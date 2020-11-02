/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_isvalid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollero- <aollero@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 16:08:06 by aollero-          #+#    #+#             */
/*   Updated: 2020/10/11 16:29:37 by aollero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/parse_isvalid.h"

int		is_inside(char c)
{
	if (c == '0' || c == '2' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	else
		return (0);
}

int		isvalidchr(char c)
{
	return (is_inside(c) || c == ' ' || c == '1');
}

int		isbeginvalid(char *line)
{
	if (*line == '1')
		return (1);
	if (*line == ' ')
	{
		while (*line == ' ')
			line++;
		if (*line == '1')
			return (1);
	}
	return (0);
}

int		is2chrvalid(char a, char b)
{
	if (!isvalidchr(a) || !(isvalidchr(b) || b == '\0') ||
		(is_inside(a) && b == ' ') || (a == ' ' && is_inside(b)) ||
		(is_inside(a) && b == '\0'))
		return (0);
	return (1);
}

int		iscolvalid(t_array *array, size_t j)
{
	char	*a;
	char	*b;
	size_t	i;

	i = 0;
	while (i < array->m - 1)
	{
		a = elem(array, i, j);
		b = elem(array, i + 1, j);
		if (!is2chrvalid(*a, *b) || (is_inside(*b) && i == array->m - 2))
			return (0);
		i++;
	}
	return (1);
}
