/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast1.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollero- <aollero@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 12:01:34 by aollero-          #+#    #+#             */
/*   Updated: 2020/10/12 12:06:21 by aollero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST1_H
# define RAYCAST1_H
# include "cubconf.h"
# include "raycast2.h"

void	sprite_loop1(t_raycast *rc, t_map *map, t_player *pl);
void	sprite_loop0(t_raycast *rc, t_map *map, t_player *pl, t_array *(im[6]));
void	drawframe(t_raycast *rc, t_map *map, t_player *pl, t_array *(img[6]));
void	createbmpfile(t_array *im, t_bmp *bitmap);
void	formatbmp(t_array *image);

#endif
