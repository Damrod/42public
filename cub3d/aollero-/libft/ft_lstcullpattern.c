/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcullpattern.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollero- <aollero@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 11:48:43 by aollero-          #+#    #+#             */
/*   Updated: 2020/09/28 13:42:48 by aollero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_lstcullpat(t_list **list, int *mask, void (*delcnt)(void *),
					void (*delnde)(void *))
{
	t_list	**indirect;
	int		flag;
	int		sz;
	int		i;
	t_list	*aux;

	sz = 0;
	i = 0;
	indirect = list;
	while (*indirect)
	{
		flag = 1;
		if (mask[i])
		{
			aux = *indirect;
			*indirect = (*indirect)->next;
			ft_lstdelone(aux, delcnt, delnde);
			sz++;
			flag = 0;
		}
		i++;
		if (flag && *indirect)
			indirect = &(*indirect)->next;
	}
	return (sz);
}

static int	ft_lstdupmask(t_list *list, int *mask, int lstsz)
{
	int		i;
	int		maskidx;
	void	*resul[lstsz];

	i = 0;
	maskidx = 0;
	ft_memset(resul, 0, sizeof(void *) * lstsz);
	ft_memset(mask, 255, sizeof(int) * lstsz);
	while (list)
	{
		mask[maskidx] = 1;
		if (ft_findptrinarray(resul, list->content, i) == -1)
		{
			resul[i] = list->content;
			mask[maskidx] = 0;
			i++;
		}
		list = list->next;
		maskidx++;
	}
	return (i);
}

int			ft_lstdeldup(t_list **list, void (*delnde)(void *))
{
	int mask[ft_lstsize((*list)) + 1];
	int sz;

	sz = ft_lstdupmask((*list), mask, ft_lstsize((*list)) + 1);
	ft_lstcullpat(list, mask, NULL, delnde);
	return (sz);
}
