/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollero- <aollero@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 13:49:23 by aollero-          #+#    #+#             */
/*   Updated: 2020/10/12 12:13:37 by aollero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cubconf.h"
#include "../incs/mng_imgs.h"

int		closecross(t_game *game)
{
	mlx_destroy_window(game->mlx->mlx, game->mlx->win);
	cleanupeverything(game);
	exit(0);
}

void	grabmove(int keycode, t_game *game, int cd1)
{
	double aux[2];

	if (cd1 == XK_a)
	{
		aux[0] = *game->map->player->plane[0];
		aux[1] = *game->map->player->plane[1];
	}
	else
	{
		aux[0] = -*game->map->player->dir[0];
		aux[1] = -*game->map->player->dir[1];
	}
	norm_vector(&aux, (keycode == cd1 ? -MOV_SPEED : MOV_SPEED));
	if (*(char *)elem(game->map->array, game->map->player->posx + aux[0],
		game->map->player->posy) == '1' || *(char *)elem(game->map->array,
		game->map->player->posx + aux[0], game->map->player->posy) == '2')
		aux[0] = 0;
	if (*(char *)elem(game->map->array, game->map->player->posx,
		game->map->player->posy + aux[1]) == '1' ||
		*(char *)elem(game->map->array, game->map->player->posx,
						game->map->player->posy + aux[1]) == '2')
		aux[1] = 0;
	move_point(game->map->player->pos, aux);
}

int		grabkeys(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		closecross(game);
	if (keycode == XK_Right)
		rot2vect2(game->map->player->dir, game->map->player->plane, ROT_SPEED);
	if (keycode == XK_Left)
		rot2vect2(game->map->player->dir, game->map->player->plane, -ROT_SPEED);
	if (keycode == XK_a || keycode == XK_d)
		grabmove(keycode, game, XK_a);
	if (keycode == XK_w || keycode == XK_s)
		grabmove(keycode, game, XK_w);
	return (0);
}

t_game	*global_config(t_game *game)
{
	sprite_populate(game, game->map->player);
	addr_img_alloc(game);
	game->raycast = my_malloc(sizeof(t_raycast));
	if (game->map->save)
		raycast(game);
	else
	{
		game->mlx->win = mlx_new_window(game->mlx->mlx, game->map->xresol,
										game->map->yresol, "Cub3D");
		mlx_loop_hook(game->mlx->mlx, raycast, game);
		mlx_hook(game->mlx->win, DestroyNotify, StructureNotifyMask,
													closecross, game);
		mlx_hook(game->mlx->win, KeyPress, KeyPressMask, grabkeys, game);
		mlx_loop(game->mlx->mlx);
	}
	return (game);
}

int		main(int argc, char **argv)
{
	t_game	*game;
	char	*config;

	if ((argc == 3 && ft_strncmp(argv[2], "--save", 6) != 0) ||
		argc > 3 || argc < 2)
		my_exit("Wrong number or order of arguments", NOARGUMENT);
	config = my_alloc(ft_strtrim(argv[1], " \f\n\r\t\v"));
	if (ft_strncmp(config + ft_strlen(config) - 4, ".cub", 4) != 0)
		my_exit("Bad config file extension", INVALIDCONFIG);
	game = parse_config_file(config);
	my_free(config);
	game->map->save = (argc == 3 ? 1 : 0);
	global_config(game);
	cleanupeverything(game);
	my_exit(NULL, 0);
	return (0);
}
