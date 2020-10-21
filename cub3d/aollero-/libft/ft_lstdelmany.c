/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelmany.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollero- <aollero@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 09:29:09 by aollero-          #+#    #+#             */
/*   Updated: 2020/09/28 11:05:27 by aollero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_lstdelmany.h"

static void	adv_lstdelmany(t_list **lst, int (*comp)(), t_delfunct *del,
														void *param)
{
	t_list	**indirect;
	t_list	*deleted;

	if (!*lst)
		return ;
	indirect = lst;
	while (*indirect)
	{
		while (*indirect && comp((*indirect)->content, param))
		{
			deleted = *indirect;
			*indirect = (*indirect)->next;
			ft_lstdelone(deleted, del->delcont, del->delnode);
		}
		if (*indirect)
			indirect = &((*indirect)->next);
	}
	return ;
}

void		ft_lstdelmany(t_list **lst, int (*comp)(), void (*del)(void *),
														void *param)
{
	t_delfunct delfunct;

	delfunct.delcont = del;
	delfunct.delnode = del;
	adv_lstdelmany(lst, comp, &delfunct, param);
}
