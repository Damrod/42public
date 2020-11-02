/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollero- <aollero@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 10:00:53 by aollero-          #+#    #+#             */
/*   Updated: 2020/10/12 10:03:47 by aollero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/get_lines.h"

t_list	*get_lines2(char *line, t_list *lines, int *height, int fd)
{
	if (islinevalid(line))
	{
		ft_lstadd_front(&lines,
						my_alloc(ft_lstnew(my_alloc(ft_strdup(line)))));
		(*height)++;
	}
	free(line);
	while (get_next_line(fd, &line) > 0)
		free(line);
	free(line);
	return (lines);
}

t_map	*get_lines1(int fd, int *height, int *width, char *tracker)
{
	t_list	*lines;
	char	*line;
	t_map	*map;
	int		flag;

	map = my_malloc(sizeof(*map));
	lines = NULL;
	flag = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (!flag)
			get_config(&flag, tracker, map, line);
		if (flag)
		{
			if (!get_map(line, width, height, &lines))
				break ;
		}
	}
	my_free(tracker);
	map->lines = get_lines2(line, lines, height, fd);
	return (map);
}

char	*get_lines0(char *path, int *fd)
{
	int		i;
	char	*tracker;

	if ((*fd = open(path, O_RDONLY)) < 0)
		my_exit(strerror(errno), errno);
	tracker = my_malloc(sizeof(char) * (8 + 1));
	tracker[8] = '\0';
	i = 0;
	while (i < 8)
		tracker[i++] = '0';
	return (tracker);
}

t_map	*get_lines_mngr(char *path, int *height, int *width)
{
	t_map	*map;
	char	*tracker;
	int		fd;

	tracker = get_lines0(path, &fd);
	map = get_lines1(fd, height, width, tracker);
	close(fd);
	return (map);
}

t_map	*getnchecklines(char *path)
{
	int		height;
	int		width;
	t_map	*map;
	t_array	*arr;
	char	**arrlines;

	height = 0;
	width = 0;
	map = get_lines_mngr(path, &height, &width);
	arr = alloc_matrix(height, width, 0, NULL);
	ft_memset(arr->cset, ' ', width * height);
	arrlines = (char**)my2alloc(ft_lsttoarr(map->lines, &height), -1);
	ft_lstclear(&map->lines, NULL, my_free);
	height = 0;
	while (arrlines[height])
	{
		ft_wrtptr(elem(arr, height, 0), arrlines[height]);
		my_free(arrlines[height]);
		height++;
	}
	my_free(arrlines);
	map->array = arr;
	return (map);
}
