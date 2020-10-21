/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getncheck_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollero- <aollero@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 10:05:39 by aollero-          #+#    #+#             */
/*   Updated: 2020/10/12 10:10:38 by aollero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GETNCHECK_MAP_H
# define GETNCHECK_MAP_H

# include "cubconf.h"
# include "parse_fields.h"
# include "parse_isvalid2.h"

int		parse_config(char *ln, t_map *map, char tracker[8]);
void	get_config(int *flag, char *tracker, t_map *map, char *line);
int		get_map(char *line, int *width, int *height, t_list **lines);
int		check_4chr(t_map *map);
int		check_map_valid(t_map *map);

#endif
