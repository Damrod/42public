/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configure_sprites.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollero- <aollero@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 10:55:52 by aollero-          #+#    #+#             */
/*   Updated: 2020/10/12 11:03:11 by aollero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIGURE_SPRITES_H
# define CONFIGURE_SPRITES_H
# include "cubconf.h"
# include "parse_isvalid2.h"
# include "algebra_utils.h"
# include "getncheck_map.h"
# include "get_lines.h"
# include "configure_map.h"

t_game		*parse_config_file(char *path);
int			sort_sprites(t_point *point, t_pdist **sprites, unsigned size);
int			sprite_populate(t_game *game, t_player *pl);
int			sprite_destroy(t_game *game, t_player *pl);

#endif
