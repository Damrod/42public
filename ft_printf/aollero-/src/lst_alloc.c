/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_alloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollero- <aollero@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 11:28:39 by aollero-          #+#    #+#             */
/*   Updated: 2020/08/05 19:30:28 by aollero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/lst_alloc.h"

static t_fplholder	*pl_alloc2(t_fplholder *plholder)
{
	*plholder->wthtms = -1;
	plholder->has_varwth = 0;
	*plholder->prectms = -1;
	plholder->has_varprec = 0;
	plholder->type = -2;
	plholder->res = NULL;
	plholder->arg = NULL;
	plholder->res_len = -1;
	plholder->is_arg = -1;
	plholder->is_out = -1;
	return (plholder);
}

t_fplholder			*pl_alloc(void)
{
	t_fplholder		*plholder;

	if (!(plholder = malloc(sizeof(*plholder))))
		return (NULL);
	plholder->startptr = NULL;
	plholder->endptr = NULL;
	plholder->flag = 0;
	if (!(plholder->wthtms = malloc(sizeof(int))))
	{
		free(plholder);
		return (NULL);
	}
	if (!(plholder->prectms = malloc(sizeof(int))))
	{
		free(plholder->wthtms);
		free(plholder);
		return (NULL);
	}
	return (pl_alloc2(plholder));
}

t_args				*arg_alloc(void)
{
	t_args			*arg;

	if (!(arg = malloc(sizeof(*arg))))
		return (NULL);
	arg->type = -2;
	arg->param.nbr = 0;
	return (arg);
}

t_out				*out_alloc(void)
{
	t_out			*out;

	if (!(out = malloc(sizeof(*out))))
		return (NULL);
	out->str = NULL;
	out->len = NULL;
	return (out);
}

int					app_lst(t_list **list, void *(*alloc)(void), char bool_back)
{
	void			*aux;
	t_list			*item;

	if (!*list)
	{
		if ((aux = (*alloc)()))
			*list = ft_lstnew(aux);
		else
			return (1);
	}
	else if (bool_back)
	{
		if ((item = ft_lstnew((*alloc)())))
			ft_lstadd_back(list, item);
		else
			return (1);
	}
	else
	{
		if ((item = ft_lstnew((*alloc)())))
			ft_lstadd_front(list, item);
		else
			return (1);
	}
	return (0);
}
