/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollero- <aollero@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 11:18:53 by aollero-          #+#    #+#             */
/*   Updated: 2020/10/12 12:19:43 by aollero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/raycast2.h"

void	conf_rc_loop(t_raycast *rc, t_map *map, t_player *pl)
{
	rc->camerax = 2 * rc->x / ((double)map->xresol) - 1;
	rc->raydirx = pl->dirx + pl->planex * rc->camerax;
	rc->raydiry = pl->diry + pl->planey * rc->camerax;
	rc->mapx = (int)pl->posx;
	rc->oldmapx = rc->mapx;
	rc->mapy = (int)pl->posy;
	rc->oldmapy = rc->mapy;
	rc->deltadistx = fabs(1 / rc->raydirx);
	rc->deltadisty = fabs(1 / rc->raydiry);
	rc->hit = 0;
	if (rc->raydirx < 0 && (rc->stepx = -1) == -1)
		rc->sidedistx = (pl->posx - rc->mapx) * rc->deltadistx;
	else
	{
		rc->stepx = 1;
		rc->sidedistx = (rc->mapx + 1 - pl->posx) * rc->deltadistx;
	}
	if (rc->raydiry < 0 && (rc->stepy = -1) == -1)
		rc->sidedisty = (pl->posy - rc->mapy) * rc->deltadisty;
	else
	{
		rc->stepy = 1;
		rc->sidedisty = (rc->mapy + 1 - pl->posy) * rc->deltadisty;
	}
}

void	verlinebuff(t_map *map, t_raycast *rc, t_array *(img[6]))
{
	int				j;
	unsigned int	*start;

	j = 0;
	start = (unsigned int *)elem(img[0], j, rc->x);
	while (j < rc->drawst)
	{
		*(start + j * map->xresol) = map->ceilcolor;
		j++;
	}
	while (j < rc->drawend)
	{
		rc->texy = (int)rc->texpos & (img[rc->texnum]->m - 1);
		rc->texpos += rc->step;
		rc->color = *(unsigned int *)elem(img[rc->texnum], rc->texy, rc->texx);
		if (((rc->side == 0 && rc->oldmapx - rc->mapx < 0) || (rc->side == 1 &&
												rc->oldmapy - rc->mapy < 0)))
			rc->color = (rc->color >> 1) & 8355711;
		*(start + j * map->xresol) = rc->color;
		j++;
	}
	while (j < map->yresol)
		*(start + (j++) * map->xresol) = map->floorcolor;
}

void	text_conf(t_raycast *rc, t_map *map, t_player *pl, t_array *(img[6]))
{
	if (rc->side == 0 && rc->oldmapx - rc->mapx < 0)
		rc->texnum = 1;
	else if (rc->side == 0)
		rc->texnum = 2;
	if (rc->side == 1 && rc->oldmapy - rc->mapy > 0)
		rc->texnum = 3;
	else if (rc->side == 1)
		rc->texnum = 4;
	if (rc->side == 0)
		rc->wallx = pl->posy + rc->perpwalldist * rc->raydiry;
	else
		rc->wallx = pl->posx + rc->perpwalldist * rc->raydirx;
	rc->wallx -= floor((rc->wallx));
	rc->texx = (int)(rc->wallx * (double)img[rc->texnum]->n);
	if (rc->side == 0 && rc->raydirx > 0)
		rc->texx = img[rc->texnum]->n - rc->texx - 1;
	if (rc->side == 1 && rc->raydiry < 0)
		rc->texx = img[rc->texnum]->n - rc->texx - 1;
	rc->step = 1.0 * img[rc->texnum]->m / rc->lnheight;
	rc->texpos = (rc->drawst - map->yresol / 2 + rc->lnheight / 2) * rc->step;
}

double	dda_alg(t_raycast *rc, t_map *map, t_player *pl)
{
	while (rc->hit == 0)
	{
		if (rc->sidedistx < rc->sidedisty)
		{
			rc->sidedistx += rc->deltadistx;
			rc->mapx += rc->stepx;
			rc->side = 0;
		}
		else
		{
			rc->sidedisty += rc->deltadisty;
			rc->mapy += rc->stepy;
			rc->side = 1;
		}
		if (*(char *)elem(map->array, rc->mapx, rc->mapy) == '1')
			rc->hit = 1;
		else if ((rc->oldmapx = rc->mapx) == rc->mapx)
			rc->oldmapy = rc->mapy;
	}
	if (rc->side == 0)
		return ((rc->mapx - pl->posx + (1 - rc->stepx) / 2) / rc->raydirx);
	else
		return ((rc->mapy - pl->posy + (1 - rc->stepy) / 2) / rc->raydiry);
}

void	sprite_loop2(t_raycast *rc, t_map *map, t_array *(img[6]))
{
	rc->strp = rc->drawstx;
	while (rc->strp < rc->drawendx)
	{
		rc->texx = (int)(256 * (rc->strp - (-rc->spritewidth / 2 +
					rc->spritescreenx)) * img[5]->n / rc->spritewidth) / 256;
		if (rc->transformy > 0 && rc->strp > 0 && rc->strp <
			map->xresol && rc->transformy < rc->zbuffer[rc->strp])
		{
			rc->y = rc->drawsty;
			while (rc->y < rc->drawendy)
			{
				rc->d = (rc->y - rc->vmovescreen) * 256 - map->yresol * 128 +
					rc->spriteheight * 128;
				rc->texy = ((rc->d * img[5]->m) / rc->spriteheight) / 256;
				rc->color = *(unsigned int *)elem(img[5], rc->texy, rc->texx);
				if ((rc->color & 0x00ffffff) != 0)
					*(unsigned int *)elem(img[0], rc->y, rc->strp) = rc->color;
				rc->y++;
			}
		}
		rc->strp++;
	}
}
