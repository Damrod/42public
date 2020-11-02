/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollero- <aollero@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 14:09:57 by aollero-          #+#    #+#             */
/*   Updated: 2020/10/31 14:29:29 by aollero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		main(int argc, char **argv)
{
	int		listsize;
	t_list	*list;
	int		i;

	list = NULL;
	i = 1;
	while (i < argc)
		ft_list_push_front(&list, argv[i++]);
	listsize = ft_list_size(list);
	i = 0;
	while (list)
	{
		ft_putnbr(i++);
		write(1, " - element of the list starting from the head : ", 48);
		write(1, list->data, ft_strlen(list->data));
		write(1, "\n", 1);
		list = list->next;
	}
	write(1, "\nThe size of the list is : ", 27);
	ft_putnbr(listsize);
	write(1, "\n", 1);
	return (0);
}
