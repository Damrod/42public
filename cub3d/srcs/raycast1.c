/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollero- <aollero@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 12:00:39 by aollero-          #+#    #+#             */
/*   Updated: 2020/10/12 12:04:44 by aollero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/raycast1.h"

void	sprite_loop1(t_raycast *rc, t_map *map, t_player *pl)
{
	double sprx;
	double spry;

	sprx = pl->sortdspr[rc->x]->point->x;
	spry = pl->sortdspr[rc->x]->point->y;
	pl->sortdspr[rc->x]->point->x -= pl->posx;
	pl->sortdspr[rc->x]->point->y -= pl->posy;
	rc->invdet = 1.0 / (pl->planex * pl->diry - pl->dirx * pl->planey);
	rc->transformx = rc->invdet * (pl->diry * pl->sortdspr[rc->x]->point->x
	- pl->dirx * pl->sortdspr[rc->x]->point->y);
	rc->transformy = rc->invdet * (-pl->planey *
pl->sortdspr[rc->x]->point->x + pl->planex * pl->sortdspr[rc->x]->point->y);
	rc->spritescreenx = (int)((map->xresol / 2) * (1 + rc->transformx /
												rc->transformy));
	rc->vmovescreen = (int)(VMOVE / rc->transformy);
	rc->spriteheight = abs((int)(map->yresol / (rc->transformy))) / VDIV;
	rc->drawsty = -rc->spriteheight / 2 + map->yresol / 2 + rc->vmovescreen;
	pl->sortdspr[rc->x]->point->x = sprx;
	pl->sortdspr[rc->x]->point->y = spry;
	if (rc->drawsty < 0)
		rc->drawsty = 0;
	rc->drawendy = rc->spriteheight / 2 + map->yresol / 2 + rc->vmovescreen;
	if (rc->drawendy >= map->yresol)
		rc->drawendy = map->yresol - 1;
}

void	sprite_loop0(t_raycast *rc, t_map *map, t_player *pl, t_array *(img[6]))
{
	rc->x = 0;
	while (rc->x < (int)map->sprnbr)
	{
		sprite_loop1(rc, map, pl);
		rc->spritewidth = abs((int)(map->yresol / (rc->transformy))) / UDIV;
		rc->drawstx = -rc->spritewidth / 2 + rc->spritescreenx;
		if (rc->drawstx < 0)
			rc->drawstx = 0;
		rc->drawendx = rc->spritewidth / 2 + rc->spritescreenx;
		if (rc->drawendx >= map->xresol)
			rc->drawendx = map->xresol - 1;
		sprite_loop2(rc, map, img);
		rc->x++;
	}
}

void	drawframe(t_raycast *rc, t_map *map, t_player *pl, t_array *(img[6]))
{
	rc->zbuffer = my_malloc(sizeof(double) * map->xresol);
	rc->x = 0;
	while (rc->x < map->xresol)
	{
		conf_rc_loop(rc, map, pl);
		rc->perpwalldist = dda_alg(rc, map, pl);
		rc->zbuffer[rc->x] = rc->perpwalldist;
		rc->lnheight = (int)(map->yresol / rc->perpwalldist);
		rc->drawst = -1 * (rc->lnheight) / 2 + map->yresol / 2;
		if (rc->drawst < 0)
			rc->drawst = 0;
		rc->drawend = rc->lnheight / 2 + map->yresol / 2;
		if (rc->drawend >= map->yresol)
			rc->drawend = map->yresol - 1;
		text_conf(rc, map, pl, img);
		verlinebuff(map, rc, img);
		rc->x++;
	}
	sprite_loop0(rc, map, pl, img);
	my_free(rc->zbuffer);
	return ;
}

void	createbmpfile(t_array *im, t_bmp *bitmap)
{
	int			fd;
	size_t		i;
	size_t		j;

	i = 0;
	while (i < im->m / 2)
	{
		j = 0;
		while (j < im->n)
		{
			fd = *(int *)elem(im, i, j);
			*(uint *)elem(im, i, j) = *(uint *)elem(im, im->m - 1 - i, j);
			*(uint *)elem(im, im->m - 1 - i, j) = (uint)fd;
			j++;
		}
		i++;
	}
	if ((fd = open("screenshot.bmp", O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR |
										S_IRGRP | S_IWGRP | S_IROTH)) == -1)
		my_exit(strerror(errno), errno);
	j = write(fd, bitmap, sizeof(*bitmap));
	(void)j;
	j = write(fd, im->cset, im->setsz * im->usz);
	(void)j;
	close(fd);
}

void	formatbmp(t_array *image)
{
	t_bmp	bitmap;

	bitmap.bftype = 0x4d42;
	bitmap.bfsize = sizeof(bitmap) + image->setsz * image->usz;
	bitmap.bfreserved1 = 0;
	bitmap.bfreserved2 = 0;
	bitmap.bfoffbits = sizeof(bitmap);
	bitmap.bisize = 40;
	bitmap.biwidth = image->n;
	bitmap.biheight = image->m;
	bitmap.biplanes = 1;
	bitmap.bibitcount = image->usz * 8;
	bitmap.bicompression = 0;
	bitmap.bisizeimage = image->setsz * image->usz;
	bitmap.bixpelspermeter = 0xb13;
	bitmap.biypelspermeter = 0xb13;
	bitmap.biclrused = 0;
	bitmap.biclrimportant = 0;
	createbmpfile(image, &bitmap);
}
