/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lines.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollero- <aollero@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 10:01:37 by aollero-          #+#    #+#             */
/*   Updated: 2020/10/12 10:13:32 by aollero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_LINES_H
# define GET_LINES_H
# include "cubconf.h"
# include "parse_isvalid2.h"
# include "getncheck_map.h"

t_list	*get_lines2(char *line, t_list *lines, int *height, int fd);
t_map	*get_lines1(int fd, int *height, int *width, char *tracker);
char	*get_lines0(char *path, int *fd);
t_map	*get_lines_mngr(char *path, int *height, int *width);
t_map	*getnchecklines(char *path);

#endif
