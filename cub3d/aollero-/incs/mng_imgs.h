/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mng_imgs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollero- <aollero@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 12:09:07 by aollero-          #+#    #+#             */
/*   Updated: 2020/10/12 12:11:25 by aollero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MNG_IMGS_H
# define MNG_IMGS_H
# include "cubconf.h"
# include "configure_sprites.h"
# include "raycast1.h"

int		raycast(t_game *game);
void	imgs_alloc(t_game *game);
void	imgs_destroy(t_game *game);
void	addr_img_alloc(t_game *game);
void	cleanupeverything(t_game *game);

#endif
