/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollero- <aollero@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 16:07:06 by aollero-          #+#    #+#             */
/*   Updated: 2020/09/28 11:27:31 by aollero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	next_line(char **line, char **remainder,
										long int *bt_rd)
{
	char *aux;
	char *newl;

	if (*bt_rd < 0)
		return (-1);
	if ((!(*bt_rd) && !(*remainder)) || (!(newl = ft_strchr(*remainder, '\n'))))
	{
		if (!(*bt_rd) && !(*remainder))
			*line = ft_strdup("");
		else
		{
			*line = *remainder;
			*remainder = NULL;
		}
		return (0);
	}
	else
	{
		*newl = 0;
		*line = ft_strdup(*remainder);
		aux = ft_strdup(newl + 1);
		free(*remainder);
		*remainder = aux;
		return (1);
	}
}

int			get_next_line(int fd, char **line)
{
	char			*buff;
	static char		*remainder[MAX_FD] = {NULL};
	long int		bytes_read;
	char			*aux;

	if ((!line || fd < 0 || BUFFER_SIZE < 1 || !(buff = malloc(BUFFER_SIZE + 1))
		|| (read(fd, buff, 0) < 0)))
		return (-1);
	while ((bytes_read = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		*(buff + bytes_read) = 0;
		if (!(*(remainder + fd)))
			*(remainder + fd) = ft_strdup(buff);
		else
		{
			aux = ft_strjoin(*(remainder + fd), buff);
			free(*(remainder + fd));
			*(remainder + fd) = aux;
		}
		if (ft_strchr(*(remainder + fd), '\n'))
			break ;
	}
	free(buff);
	return (next_line(line, remainder + fd, &bytes_read));
}
