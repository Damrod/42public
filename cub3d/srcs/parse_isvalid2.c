/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_isvalid2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollero- <aollero@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 21:34:31 by aollero-          #+#    #+#             */
/*   Updated: 2020/10/11 21:40:10 by aollero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/parse_isvalid2.h"

int		is4chvalid(t_array *array, size_t i, size_t j)
{
	char	*a;
	char	*b;
	char	*c;
	char	*d;

	a = elem(array, i, j);
	b = elem(array, i + 1, j);
	c = elem(array, i, j + 1);
	d = elem(array, i + 1, j + 1);
	if ((is_inside(*a) && *d == ' ') || (*a == ' ' && is_inside(*d)) ||
		(*b == ' ' && is_inside(*c)) || (is_inside(*b) && *c == ' '))
		return (0);
	return (1);
}

int		islinevalid(char *line)
{
	if (!isbeginvalid(line))
		return (0);
	while (*(line) != '\0')
	{
		if (!is2chrvalid(*line, *(line + 1)))
			return (0);
		line++;
	}
	return (1);
}

size_t	charposinarr(t_array *arr, t_byte *key, ssize_t *i, ssize_t *j)
{
	unsigned char	*str;
	unsigned char	*found;
	size_t			offset;

	str = arr->cset;
	if (*i == -1 || *j == -1)
		found = ft_arrbyte(arr, key);
	else
		found = key;
	offset = (found - str) / arr->usz;
	*i = offset / arr->n;
	*j = offset % arr->n;
	return (offset);
}

int		howmanychrinstr(char *str, int c)
{
	size_t i;

	i = 0;
	while (*str)
	{
		if (*str == c)
			i++;
		str++;
	}
	return (i);
}

char	is_startpt_ok(t_array *array)
{
	size_t	i;
	char	player;
	int		ret;

	i = 0;
	i += (ret = howmanychrinstr(array->cset, 'N'));
	player = (ret > 0 ? 'N' : '\0');
	i += (ret = howmanychrinstr(array->cset, 'S'));
	player = ((ret > 0) ? 'S' : player);
	i += (ret = howmanychrinstr(array->cset, 'E'));
	player = ((ret > 0) ? 'E' : player);
	i += (ret = howmanychrinstr(array->cset, 'W'));
	player = ((ret > 0) ? 'W' : player);
	if (i != 1)
		return (0);
	else
		return (player);
}
