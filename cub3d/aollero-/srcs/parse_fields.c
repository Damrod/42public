/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fields.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollero- <aollero@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 21:50:07 by aollero-          #+#    #+#             */
/*   Updated: 2020/10/11 21:52:16 by aollero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/parse_fields.h"

int		parse_resolution(char *ln, t_map *map, char *tracker)
{
	if (tracker[0] == '0' && *ln == 'R')
	{
		ln++;
		map->xresol = ft_atoi_adv(&ln);
		map->yresol = ft_atoi_adv(&ln);
		adv_spaces(&ln);
		if (*ln || map->yresol < 1 || map->xresol < 1)
			my_exit("Resolution improperly formatted or too small",
				INVALIDCONFIG);
		tracker[0] = '1';
		return (0);
	}
	else if (tracker[0] == '1' && *ln == 'R')
		my_exit("Resolution repeated", INVALIDCONFIG);
	return (1);
}

int		parse_textures(char *ln, t_map *map, char *tracker, char *a)
{
	char	**aux;
	int		trackpos;

	aux = NULL;
	if (ft_strncmp(a, "NO", 2) == 0 && (trackpos = 1))
		aux = &(map->ntext);
	if (ft_strncmp(a, "SO", 2) == 0 && (trackpos = 2))
		aux = &(map->stext);
	if (ft_strncmp(a, "WE", 2) == 0 && (trackpos = 3))
		aux = &(map->wtext);
	if (ft_strncmp(a, "EA", 2) == 0 && (trackpos = 4))
		aux = &(map->etext);
	if (*a == 'S' && ft_isspace(a[1]) && (trackpos = 5))
		aux = &(map->sprite);
	if (tracker[trackpos] == '0' && (ft_strncmp(a, ln, 2) == 0 ||
		(*a == 'S' && ft_isspace(a[1]) && *ln == 'S' && ft_isspace(ln[1]))))
	{
		*aux = my_alloc(ft_strtrim(ln + 2, " \f\n\r\t\v"));
		tracker[trackpos] = '1';
		return (0);
	}
	else if (tracker[trackpos] == '1' && (ft_strncmp(a, ln, 2) == 0 ||
		(*a == 'S' && ft_isspace(a[1]) && *ln == 'S' && ft_isspace(ln[1]))))
		my_exit("Textures repeated", INVALIDCONFIG);
	return (1);
}

int		parse_colors2(char *ln, unsigned int *aux)
{
	int	red;
	int	green;
	int	blue;

	ln++;
	red = ft_atoi_adv(&ln);
	adv_spaces(&ln);
	if (*ln == ',')
		ln++;
	else
		return (1);
	green = ft_atoi_adv(&ln);
	adv_spaces(&ln);
	if (*ln == ',')
		ln++;
	else
		return (1);
	blue = ft_atoi_adv(&ln);
	adv_spaces(&ln);
	if (*ln || red > 255 || blue > 255 || green > 255 || red < 0 || blue < 0 ||
		green < 0)
		my_exit("Colors out of range or junk at end of line", INVALIDCONFIG);
	*aux = (red << 16 | green << 8 | blue);
	return (0);
}

int		parse_colors(char *ln, t_map *map, char *tracker, char a)
{
	unsigned int	*aux;
	int				trackpos;

	aux = NULL;
	if (a == 'F' && (trackpos = 6))
		aux = &(map->floorcolor);
	if (a == 'C' && (trackpos = 7))
		aux = &(map->ceilcolor);
	if (tracker[trackpos] == '0' && *ln == a)
	{
		if (!parse_colors2(ln, aux))
		{
			tracker[trackpos] = '1';
			return (0);
		}
		else
			my_exit("Colors not properly formatted", INVALIDCONFIG);
	}
	else if (tracker[trackpos] == '1' && *ln == a)
		my_exit("Colors repeated", INVALIDCONFIG);
	return (1);
}

int		handle_configcases(char *ln, t_map *map, char tracker[8])
{
	if (!parse_resolution(ln, map, tracker))
		return (0);
	if (!parse_textures(ln, map, tracker, "NO"))
		return (0);
	if (!parse_textures(ln, map, tracker, "SO"))
		return (0);
	if (!parse_textures(ln, map, tracker, "WE"))
		return (0);
	if (!parse_textures(ln, map, tracker, "EA"))
		return (0);
	if (!parse_textures(ln, map, tracker, "S "))
		return (0);
	if (!parse_colors(ln, map, tracker, 'F'))
		return (0);
	if (!parse_colors(ln, map, tracker, 'C'))
		return (0);
	if (*ln == '\0')
		return (0);
	return (1);
}
