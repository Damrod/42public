/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollero- <aollero@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 18:34:43 by aollero-          #+#    #+#             */
/*   Updated: 2020/08/05 18:39:25 by aollero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/parse_fstr.h"

int		handle_plhold(const char **str, t_list **arglist, t_list **plholders)
{
	t_list		*aux;

	if (**str == '%')
	{
		if (app_lst(plholders, (void *(*)(void))&pl_alloc, LST_ORDER))
			return (1);
		aux = blst(*plholders, LST_ORDER);
		parse_plholder(str, (t_fplholder **)&(aux->content), arglist);
	}
	return (0);
}

void	out_strlit(t_fplholder *plhold, const char *start, char *resul)
{
	plhold->startptr = start;
	plhold->endptr = start + plhold->res_len;
	plhold->res = resul;
	plhold->is_arg = 0;
	plhold->is_out = 1;
	plhold->type = -1;
	return ;
}

int		handle_strlit(const char **str, t_list **plholders, int *dowhile)
{
	char		*aux;
	t_fplholder	*aux2;

	if (*(*str) && ((*(*str) != '%' && *dowhile) || (*plholders != NULL &&
	((((t_fplholder *)((t_list *)blst(*plholders, LST_ORDER))->content)->
	endptr == *str) && *(*(str)) != '%' && *(*str)))))
	{
		if (app_lst(plholders, (void *(*)(void))&pl_alloc, LST_ORDER))
			return (1);
		aux2 = ((t_fplholder *)((t_list *)blst(*plholders, LST_ORDER))->
				content);
		aux2->res_len = (ft_strchr(*str, '%') ? ft_strchr(*str, '%') :
										ft_strchr(*str, '\0')) - *str;
		aux = ft_substr(*str, 0, aux2->res_len);
		out_strlit(aux2, *str, aux);
		(*str)++;
	}
	else if (*(*str) == '%')
		return (0);
	else
		(*str)++;
	return (0);
}

t_list	*parse_format(const char *str, t_list **arglist)
{
	t_list		*plholders;
	int			dowhile;

	dowhile = 1;
	plholders = NULL;
	while (*str)
	{
		if (handle_plhold(&str, arglist, &plholders))
			return (NULL);
		if (handle_strlit(&str, &plholders, &dowhile))
			return (NULL);
		dowhile = 0;
	}
	return (plholders);
}

int		out_char(t_fplholder *phold, t_out *out, t_args *arg, char bool_perc)
{
	char	*resul;
	int		width;
	int		charpos;

	width = (*(phold->wthtms) > -1 ? *(phold->wthtms) : 1);
	if (!(resul = ft_calloc(width + 1, sizeof(char))))
		return (1);
	ft_memset(resul, (phold->flag == 2 ? '0' : ' '), width);
	charpos = (phold->flag == 1 ? 0 : width - 1);
	*(resul + charpos) = (arg && !bool_perc ? arg->param.nbr : '%');
	*(resul + width) = 0;
	phold->res = resul;
	phold->is_out = 1;
	phold->res_len = width;
	out->len = &phold->res_len;
	out->str = &phold->res;
	return (0);
}
