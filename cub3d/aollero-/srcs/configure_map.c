/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configure_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollero- <aollero@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 10:28:20 by aollero-          #+#    #+#             */
/*   Updated: 2020/10/12 16:57:33 by aollero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/configure_map.h"

void	orient_player(t_map *map, char orient)
{
	if (orient == 'N')
	{
		map->player->dirx = -1;
		map->player->diry = 0;
	}
	if (orient == 'S')
	{
		map->player->dirx = 1;
		map->player->diry = 0;
	}
	if (orient == 'E')
	{
		map->player->dirx = 0;
		map->player->diry = 1;
	}
	if (orient == 'W')
	{
		map->player->dirx = 0;
		map->player->diry = -1;
	}
}

char	*errmess(t_map *map, int orient)
{
	char *prelude;
	char *errors[6];
	char *ret;

	prelude = NULL;
	if (orient == 0 && (errors[2] = map->ntext))
		prelude = my_alloc(ft_strdup("North texture: "));
	if (orient == 1 && (errors[2] = map->stext))
		prelude = my_alloc(ft_strdup("South texture: "));
	if (orient == 2 && (errors[2] = map->etext))
		prelude = my_alloc(ft_strdup("East texture: "));
	if (orient == 3 && (errors[2] = map->wtext))
		prelude = my_alloc(ft_strdup("West texture: "));
	if (orient == 4 && (errors[2] = map->sprite))
		prelude = my_alloc(ft_strdup("Sprite image: "));
	errors[0] = prelude;
	errors[1] = my_alloc(ft_strdup("cannot open `"));
	errors[3] = my_alloc(ft_strdup("' ("));
	errors[4] = strerror(errno);
	errors[5] = my_alloc(ft_strdup(")"));
	ret = my_alloc(ft_strjoin_ult(6, (const char **)errors, ""));
	my_free(prelude);
	return (ret);
}

void	checkpicpaths(t_map *map)
{
	int fd;

	if (((fd = open(map->ntext, O_RDONLY)) == -1))
		my_exit(errmess(map, 0), errno);
	else
		close(fd);
	if (((fd = open(map->stext, O_RDONLY)) == -1))
		my_exit(errmess(map, 1), errno);
	else
		close(fd);
	if (((fd = open(map->etext, O_RDONLY)) == -1))
		my_exit(errmess(map, 2), errno);
	else
		close(fd);
	if (((fd = open(map->wtext, O_RDONLY)) == -1))
		my_exit(errmess(map, 3), errno);
	else
		close(fd);
	if (((fd = open(map->sprite, O_RDONLY)) == -1))
		my_exit(errmess(map, 4), errno);
	else
		close(fd);
}

t_game	*my_mlx_init(t_map *map)
{
	t_vars	*vars;
	int		x;
	int		y;
	t_game	*game;

	vars = my_malloc(sizeof(*vars));
	game = my_malloc(sizeof(*game));
	game->mlx = vars;
	game->map = map;
	vars->mlx = my_alloc(mlx_init());
	mlx_get_screen_size(vars->mlx, &x, &y);
	map->xresol = fmin(map->xresol, x);
	map->yresol = fmin(map->yresol, y);
	return (game);
}

t_game	*configure_map(t_map *map, char orient)
{
	long	x;
	long	y;

	x = -1;
	y = -1;
	charposinarr(map->array, (t_byte *)&orient, &x, &y);
	map->player->posx = (double)x + 0.5;
	map->player->posy = (double)y + 0.5;
	orient_player(map, orient);
	map->player->pos[0] = &map->player->posx;
	map->player->pos[1] = &map->player->posy;
	map->player->dir[0] = &map->player->dirx;
	map->player->dir[1] = &map->player->diry;
	map->player->planex = map->player->dirx;
	map->player->planey = map->player->diry;
	map->player->plane[0] = &map->player->planex;
	map->player->plane[1] = &map->player->planey;
	rotvect2(map->player->plane, CAM_WIDTH, M_PI_2);
	map->sprnbr = howmanychrinstr(map->array->cset, '2');
	checkpicpaths(map);
	return (my_mlx_init(map));
}
