/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fields.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollero- <aollero@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 21:51:07 by aollero-          #+#    #+#             */
/*   Updated: 2020/10/11 21:52:03 by aollero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_FIELDS_H
# define PARSE_FIELDS_H

# include "../libft/libft.h"
# include "cubconf.h"

int		parse_resolution(char *ln, t_map *map, char *tracker);
int		parse_textures(char *ln, t_map *map, char *tracker, char *a);
int		parse_colors2(char *ln, unsigned int *aux);
int		parse_colors(char *ln, t_map *map, char *tracker, char a);
int		handle_configcases(char *ln, t_map *map, char tracker[8]);

#endif
