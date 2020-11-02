/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_isvalid2.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollero- <aollero@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 21:36:23 by aollero-          #+#    #+#             */
/*   Updated: 2020/10/11 21:39:58 by aollero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_ISVALID2_H
# define PARSE_ISVALID2_H
# include "../libft/libft.h"
# include "parse_isvalid.h"

int		is4chvalid(t_array *array, size_t i, size_t j);
int		islinevalid(char *line);
size_t	charposinarr(t_array *arr, t_byte *key, ssize_t *i, ssize_t *j);
int		howmanychrinstr(char *str, int c);
char	is_startpt_ok(t_array *array);

#endif
