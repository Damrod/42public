/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollero- <aollero@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 21:49:42 by aollero-          #+#    #+#             */
/*   Updated: 2020/07/02 20:36:42 by aollero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *resul;
	t_list *new_head;

	if (!lst || !(del) || !(f))
		return (NULL);
	if (!(new_head = ft_lstnew(f(lst->content))))
	{
		ft_lstdelone(new_head, del);
		return (NULL);
	}
	while (lst->next)
	{
		if (!(resul = ft_lstnew(f(lst->next->content))))
		{
			ft_lstclear(&new_head, del);
			return (NULL);
		}
		ft_lstadd_back(&new_head, resul);
		lst = lst->next;
	}
	return (new_head);
}
