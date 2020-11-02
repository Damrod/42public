/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollero- <aollero@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 21:47:16 by aollero-          #+#    #+#             */
/*   Updated: 2020/10/31 01:28:09 by aollero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

long	ft_putstr(const char *str, int fd)
{
	return (ft_write(fd, str, ft_strlen(str)));
}

long	quoted_str(const char *str, int fd)
{
	long aux;

	ft_write(fd, "\"", 1);
	aux = ft_putstr(str, fd);
	ft_write(fd, "\"\n", 2);
	return (aux);
}

void	dbg(long ret, char *func, int fd)
{
	ft_putstr("The return value of ", fd);
	ft_putstr(func, fd);
	ft_putstr(" is : ", fd);
	ft_putnbr(ret);
	ft_putstr("\nerrno is: ", fd);
	ft_putnbr(errno);
	ft_putstr("\nStrerror is: ", fd);
	ft_putstr(strerror(errno), fd);
	ft_write(fd, "\n", 1);
}

void	main2(char **argv, char *str)
{
	int fd;
	int ret_rd;

	ft_putstr("We're gonna " "ft_strcpy" " argv[2] on top of that " "ft_strdup"
				" :", 1);
	ft_strcpy(str, argv[2]);
	quoted_str(str, 1);
	ft_putstr("We're gonna " "ft_read" " what's there in argv[3] and place "
				"ft_atoi(argv[4]) characters into " "ft_strdup" " :\n", 1);
	fd = open(argv[3], O_RDONLY);
	ret_rd = ft_read(fd, str, ft_atoi(argv[4]));
	quoted_str(str, 1);
	dbg(ret_rd, "ft_read", 1);
	close(fd);
}

int		main(int argc, char **argv)
{
	char	*str;
	long	ret_wt;
	int		fd;

	if (argc < 5)
		return (1);
	fd = (argc > 5 ? ft_atoi(argv[5]) : 1);
	ft_putstr("Argv[1] is : ", 1);
	ret_wt = quoted_str(argv[1], fd);
	dbg(ret_wt, "ft_write", 1);
	ft_putstr("The " "ft_strcmp" " between argv[1] and argv[2] is : ", 1);
	ft_putnbr(ft_strcmp(argv[1], argv[2]));
	ft_write(1, "\n", 1);
	ft_putstr("The " "ft_strlen" " of argv[1] is: ", 1);
	ft_putnbr(ft_strlen(argv[1]));
	ft_write(1, "\n", 1);
	ft_putstr("A " "ft_strdup" " of argv[1] is : ", 1);
	str = ft_strdup(argv[1]);
	quoted_str(str, 1);
	main2(argv, str);
	return (0);
}
