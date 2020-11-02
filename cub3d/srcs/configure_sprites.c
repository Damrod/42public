/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configure_sprites.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollero- <aollero@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 10:53:59 by aollero-          #+#    #+#             */
/*   Updated: 2020/10/12 10:57:56 by aollero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/configure_sprites.h"

t_game		*parse_config_file(char *path)
{
	t_map			*map;
	char			orient;
	t_game			*game;

	map = getnchecklines(path);
	map->player = my_malloc(sizeof(*map->player));
	if (!(orient = check_map_valid(map)))
		my_exit(STRINVALIDMAP, INVALIDMAP);
	game = configure_map(map, orient);
	return (game);
}

static void	selectionsort(t_pdist **arr, int size)
{
	int		i;
	int		j;
	int		min_idx;

	i = 0;
	while (i < size - 1)
	{
		min_idx = i;
		j = i + 1;
		while (j < size)
		{
			if (arr[j]->d2play > arr[min_idx]->d2play)
				min_idx = j;
			j++;
		}
		keyswap(&arr[min_idx], &arr[i]);
		i++;
	}
}

int			sort_sprites(t_point *point, t_pdist **sprites, unsigned size)
{
	size_t i;

	i = 0;
	while (i < size)
	{
		sprites[i]->d2play = ft_distance(point, sprites[i]->point);
		i++;
	}
	selectionsort(sprites, size);
	return (0);
}

int			sprite_populate(t_game *game, t_player *pl)
{
	unsigned	i;
	char		*aux;
	ssize_t		x;
	ssize_t		y;

	aux = NULL;
	pl->sortdspr = my_malloc(sizeof(t_pdist *) * game->map->sprnbr);
	i = 0;
	while (i < game->map->sprnbr)
	{
		x = 0;
		y = 0;
		pl->sortdspr[i] = my_malloc(sizeof(t_pdist));
		pl->sortdspr[i]->point = my_malloc(sizeof(t_point));
		if (!aux)
			aux = ft_strchr((char *)game->map->array->cset, '2');
		else
			aux = ft_strchr(aux + 1, '2');
		charposinarr(game->map->array, (t_byte *)aux, &x, &y);
		pl->sortdspr[i]->point->x = (double)x + 0.5;
		pl->sortdspr[i]->point->y = (double)y + 0.5;
		i++;
	}
	return (0);
}

int			sprite_destroy(t_game *game, t_player *pl)
{
	size_t i;

	i = 0;
	while (i < game->map->sprnbr)
	{
		my_free(pl->sortdspr[i]->point);
		my_free(pl->sortdspr[i]);
		i++;
	}
	my_free(pl->sortdspr);
	return (0);
}
