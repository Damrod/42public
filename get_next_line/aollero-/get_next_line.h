/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollero- <aollero@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 17:40:48 by aollero-          #+#    #+#             */
/*   Updated: 2020/07/17 15:26:10 by aollero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2048
# endif
# ifndef MAX_FD
#  define MAX_FD 512
# endif

char			*ft_strjoin(char const *s1, char const *s2);

char			*ft_strdup(const char *s);

char			*ft_strchr(const char *s, int c);

int				get_next_line(int fd, char **line);

#endif
