/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configure_map.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollero- <aollero@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 10:30:10 by aollero-          #+#    #+#             */
/*   Updated: 2020/10/12 10:34:36 by aollero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIGURE_MAP_H
# define CONFIGURE_MAP_H
# include "cubconf.h"
# include "parse_isvalid2.h"

void	orient_player(t_map *map, char orient);
char	*errmess(t_map *map, int orient);
void	checkpicpaths(t_map *map);
t_game	*my_mlx_init(t_map *map);
t_game	*configure_map(t_map *map, char orient);

#endif
