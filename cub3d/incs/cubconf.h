/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubconf.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollero- <aollero@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 14:21:43 by aollero-          #+#    #+#             */
/*   Updated: 2020/10/11 21:38:47 by aollero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBCONF_H
# define CUBCONF_H
# define INVALIDMAP 1
# define STRINVALIDMAP "Invalid map"
# define INVALIDCONFIG 2
# define STRINVALIDCONFIG "Invalid config"
# define NOARGUMENT	3
# define STRNOARGUMENT "No arguments provided"
# define XK_MISCELLANY
# define XK_LATIN1

/*
** rot_speed = pi/24 0.13089969389957471826
** rot_speed = pi/72 0.04363323129985823942
*/

# define ROT_SPEED 0.04363323129985823942
# define MOV_SPEED 0.05
# define CAM_WIDTH 0.66
# define UDIV 1.3
# define VDIV 1.3
# define VMOVE 100
# include <stdlib.h>
# include <X11/X.h>
# include <X11/keysymdef.h>
# include "../libft/libft.h"
# include "bmp.h"

typedef struct		s_point {
	double			x;
	double			y;
}					t_point;

typedef struct		s_pdist {
	t_point			*point;
	double			d2play;
}					t_pdist;

typedef struct		s_player {
	double			*pos[2];
	double			*dir[2];
	double			*plane[2];
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	t_pdist			**sortdspr;
}					t_player;

typedef struct		s_map {
	int				xresol;
	int				yresol;
	char			*ntext;
	char			*stext;
	char			*etext;
	char			*wtext;
	char			*sprite;
	unsigned int	floorcolor;
	unsigned int	ceilcolor;
	t_list			*lines;
	t_array			*array;
	int				save;
	unsigned int	sprnbr;
	t_player		*player;
}					t_map;

typedef struct		s_dat {
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				width;
	int				height;
}					t_dat;

typedef struct		s_vars {
	void			*mlx;
	void			*win;
}					t_vars;

typedef struct		s_raycast {
	int				x;
	int				y;
	int				d;
	double			camerax;
	double			raydirx;
	double			raydiry;
	int				mapx;
	int				mapy;
	int				oldmapx;
	int				oldmapy;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;
	double			perpwalldist;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	int				lnheight;
	int				drawst;
	int				drawend;
	int				texnum;
	double			wallx;
	int				texx;
	double			step;
	double			texpos;
	int				texy;
	unsigned int	color;
	double			*zbuffer;
	double			invdet;
	double			transformx;
	double			transformy;
	int				spritescreenx;
	int				spriteheight;
	int				drawsty;
	int				drawendy;
	int				spritewidth;
	int				drawstx;
	int				drawendx;
	int				strp;
	int				vmovescreen;
}					t_raycast;

typedef struct		s_game {
	t_vars			*mlx;
	t_dat			*(img[6]);
	t_map			*map;
	t_raycast		*raycast;
	t_array			*add_im[6];
}					t_game;

#endif
