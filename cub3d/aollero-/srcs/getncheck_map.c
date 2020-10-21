/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getncheck_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollero- <aollero@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 10:04:47 by aollero-          #+#    #+#             */
/*   Updated: 2020/10/12 10:10:51 by aollero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/getncheck_map.h"

int		parse_config(char *ln, t_map *map, char tracker[8])
{
	adv_spaces(&ln);
	if (*ln == 'R' || (*ln == 'N' && ln[1] == 'O') ||
		(*ln == 'S' && (ft_isspace(ln[1]) || ln[1] == 'O')) ||
		(*ln == 'W' && ln[1] == 'E') || (*ln == 'E' && ln[1] == 'A') ||
		*ln == 'F' || *ln == 'C' || !*ln)
		return (handle_configcases(ln, map, tracker));
	else
		my_exit(STRINVALIDCONFIG, INVALIDCONFIG);
	return (1);
}

void	get_config(int *flag, char *tracker, t_map *map, char *line)
{
	int	i;

	if (!(*flag) && ft_strncmp(tracker, "11111111", 8))
		(parse_config(line, map, tracker));
	else if (!(*flag))
	{
		i = 0;
		while (ft_isspace(line[i]))
			i++;
		if (line[i] == '1')
			*flag = 1;
		else if (line[i] != '\0')
			my_exit("Junk after configuration settings", INVALIDMAP);
	}
	if (!(*flag))
		free(line);
}

int		get_map(char *line, int *width, int *height, t_list **lines)
{
	if (ft_strchr(line, '1'))
	{
		if (!islinevalid(line))
			my_exit(STRINVALIDMAP, INVALIDMAP);
		*width = fmax(*width, (ft_strrchr(line, '1') + 1) - line);
		ft_lstadd_front(lines,
						my_alloc(ft_lstnew(my_alloc(ft_strdup(line)))));
		(*height)++;
		free(line);
		return (1);
	}
	else
		return (0);
}

int		check_4chr(t_map *map)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (i < map->array->m - 1)
	{
		j = 0;
		while (j < map->array->n - 1)
		{
			if (!is4chvalid(map->array, i, j))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		check_map_valid(t_map *map)
{
	size_t	j;
	char	ret;

	j = 0;
	while (j < map->array->n)
	{
		if (!iscolvalid(map->array, j))
			return (0);
		j++;
	}
	if (!check_4chr(map))
		return (0);
	if (!(ret = is_startpt_ok(map->array)))
		return (0);
	return (ret);
}
