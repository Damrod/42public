/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollero- <aollero@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 20:37:47 by aollero-          #+#    #+#             */
/*   Updated: 2020/10/31 14:19:15 by aollero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <errno.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

/*
** Utils
*/

void				ft_putnbr(int nbr);
int					ft_atoi(char *str);

/*
** libc prototypes
*/

long unsigned		strlen(const char *s);
long				read(int fd, void *buff, unsigned long count);
long				write(int fd, const void *buff, unsigned long count);
char				*strdup(const char *str);
char				*strcpy(char *dst, const char *src);
int					strcmp(const char *str1, const char *str2);

/*
** scope of the exercise
*/

long unsigned		ft_strlen(const char *s);
long				ft_read(int fd, void *buff, unsigned long count);
long				ft_write(int fd, const void *buff, unsigned long count);
char				*ft_strdup(const char *str);
char				*ft_strcpy(char *dst, const char *src);
int					ft_strcmp(const char *str1, const char *str2);

/*
** Bonus
*/

void				ft_list_push_front(t_list **lst, void *data);
int					ft_list_size(t_list *lst);

#endif
