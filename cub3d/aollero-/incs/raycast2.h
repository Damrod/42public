/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayscast2.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollero- <aollero@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 11:18:18 by aollero-          #+#    #+#             */
/*   Updated: 2020/10/12 11:19:47 by aollero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST2_H
# define RAYCAST2_H
# include "cubconf.h"

void	conf_rc_loop(t_raycast *rc, t_map *map, t_player *pl);
void	verlinebuff(t_map *map, t_raycast *rc, t_array *(img[6]));
void	text_conf(t_raycast *rc, t_map *map, t_player *pl, t_array *(img[6]));
double	dda_alg(t_raycast *rc, t_map *map, t_player *pl);
void	sprite_loop2(t_raycast *rc, t_map *map, t_array *(img[6]));

#endif
