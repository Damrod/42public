/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mng_imgs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollero- <aollero@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 12:08:30 by aollero-          #+#    #+#             */
/*   Updated: 2020/10/12 12:26:51 by aollero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/mng_imgs.h"

int		raycast(t_game *game)
{
	t_point		pos;

	pos.x = game->map->player->posx;
	pos.y = game->map->player->posy;
	game->img[0] = my_malloc(sizeof(t_dat));
	game->img[0]->img = my_mlx(mlx_new_image(game->mlx->mlx, game->map->xresol,
											game->map->yresol));
	game->img[0]->addr = mlx_get_data_addr(game->img[0]->img,
				&game->img[0]->bits_per_pixel, &game->img[0]->line_length,
				&game->img[0]->endian);
	game->add_im[0] = alloc_matrix(game->map->yresol, game->map->xresol, 6,
								(t_byte *)game->img[0]->addr);
	sort_sprites(&pos, game->map->player->sortdspr, game->map->sprnbr);
	drawframe(game->raycast, game->map, game->map->player, game->add_im);
	if (!game->map->save)
		mlx_put_image_to_window(game->mlx->mlx, game->mlx->win,
								game->img[0]->img, 0, 0);
	else
		formatbmp(game->add_im[0]);
	mlx_destroy_image(game->mlx->mlx, game->img[0]->img);
	my_free(game->add_im[0]);
	return (0);
}

void	imgs_alloc(t_game *game)
{
	int i;

	i = 1;
	while (i < 6)
	{
		game->img[i] = my_malloc(sizeof(t_dat));
		i++;
	}
	game->img[1]->img = my_mlx(mlx_xpm_file_to_image(game->mlx->mlx,
		game->map->ntext, &game->img[1]->width, &game->img[1]->height));
	game->img[2]->img = my_mlx(mlx_xpm_file_to_image(game->mlx->mlx,
		game->map->stext, &game->img[2]->width, &game->img[2]->height));
	game->img[3]->img = my_mlx(mlx_xpm_file_to_image(game->mlx->mlx,
		game->map->etext, &game->img[3]->width, &game->img[3]->height));
	game->img[4]->img = my_mlx(mlx_xpm_file_to_image(game->mlx->mlx,
		game->map->wtext, &game->img[4]->width, &game->img[4]->height));
	game->img[5]->img = my_mlx(mlx_xpm_file_to_image(game->mlx->mlx,
		game->map->sprite, &game->img[5]->width, &game->img[5]->height));
}

void	imgs_destroy(t_game *game)
{
	int i;

	i = 1;
	while (i < 6)
	{
		mlx_destroy_image(game->mlx->mlx, game->img[i]->img);
		my_free(game->add_im[i]->cset);
		my_free(game->add_im[i]);
		my_free(game->img[i]);
		i++;
	}
}

void	addr_img_alloc(t_game *game)
{
	int		i;

	imgs_alloc(game);
	i = 1;
	while (i < 6)
	{
		game->img[i]->addr = mlx_get_data_addr(game->img[i]->img,
		&game->img[i]->bits_per_pixel, &game->img[i]->line_length,
											&game->img[i]->endian);
		game->add_im[i] = alloc_matrix(game->img[i]->height,
				game->img[i]->width, 6, (t_byte *)game->img[i]->addr);
		i++;
	}
}

void	cleanupeverything(t_game *game)
{
	t_map *map;

	imgs_destroy(game);
	my_free(game->raycast);
	sprite_destroy(game, game->map->player);
	map = game->map;
	my_free(map->ntext);
	my_free(map->stext);
	my_free(map->etext);
	my_free(map->wtext);
	my_free(map->sprite);
	my_free(map->array->cset);
	my_free(map->array);
	my_free(map->player);
	my_free(map);
	my_free(game->mlx->mlx);
	my_free(game->mlx);
	my_free(game);
	my_exit(NULL, 0);
}
