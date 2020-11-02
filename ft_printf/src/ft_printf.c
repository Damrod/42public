/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollero- <aollero@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 12:49:33 by aollero-          #+#    #+#             */
/*   Updated: 2020/08/05 19:18:25 by aollero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"
#include "../incs/lst_rm.h"
#include "../incs/out_cat.h"

int		lst_free(t_list **plholders, t_list **arglist, t_list **output)
{
	if (*output)
		ft_lstclear(output, &out_del);
	if (*plholders)
		ft_lstclear(plholders, &pl_del);
	if (*arglist)
		ft_lstclear(arglist, &arg_del);
	return (0);
}

void	preprocess(t_list *plhold)
{
	t_fplholder	*aux;

	while (plhold)
	{
		aux = ((t_fplholder *)(plhold->content));
		if (aux->has_varwth && *aux->wthtms < 0)
		{
			*aux->wthtms *= -1;
			aux->flag = 1;
		}
		plhold = plhold->next;
	}
}

int		cr_cat_free_out(t_list **plholders, t_list **arglist)
{
	int			ret_val;
	t_list		*output;

	ret_val = 0;
	output = NULL;
	preprocess(*plholders);
	if (createoutput(*plholders, &output))
		return (-1);
	if ((ret_val = catoutput(output)) < 0)
		return (-1);
	lst_free(plholders, arglist, &output);
	return (ret_val);
}

void	va_arg_cases(va_list *list, t_args *arg)
{
	if ((arg->type < 0) || (arg->type > 9))
		return ;
	else if (arg->type == 0 || arg->type == 3 || arg->type == 4 ||
											arg->type == 9)
		arg->param.nbr = va_arg(*list, int);
	else if (arg->type == 1)
		arg->param.str = va_arg(*list, char *);
	else if (arg->type == 2)
		arg->param.ptr = va_arg(*list, void *);
	else if (arg->type == 5 || arg->type == 6 || arg->type == 7)
		arg->param.unbr = va_arg(*list, unsigned int);
	return ;
}

int		ft_printf(const char *format, ...)
{
	va_list		list;
	t_list		*arglist;
	t_list		*arghead;
	t_list		*plholders;
	char		*fmtcpy;

	arglist = NULL;
	plholders = NULL;
	fmtcpy = ft_strdup(format);
	if (!(plholders = parse_format(fmtcpy, &arglist)))
		return (-1);
	free(fmtcpy);
	arghead = arglist;
	va_start(list, format);
	while (arglist)
	{
		va_arg_cases(&list, ((t_args *)(arglist)->content));
		arglist = arglist->next;
	}
	va_end(list);
	return (cr_cat_free_out(&plholders, &arghead));
}
