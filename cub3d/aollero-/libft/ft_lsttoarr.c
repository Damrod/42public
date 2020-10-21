/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsttoarr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollero- <aollero@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 11:06:40 by aollero-          #+#    #+#             */
/*   Updated: 2020/09/28 11:07:31 by aollero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		**ft_lsttoarr(t_list *list, int *size)
{
	int		i;
	void	**retr;

	i = ft_lstsize(list);
	if (!(retr = malloc(sizeof(*retr) * (i + 1))))
		return (NULL);
	ft_memset(retr, 0, (sizeof(*retr) * (i + 1)));
	*size = i;
	while (i)
	{
		retr[i - 1] = list->content;
		list = list->next;
		i--;
	}
	return (retr);
}
