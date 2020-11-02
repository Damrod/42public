/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plholder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollero- <aollero@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 18:10:27 by aollero-          #+#    #+#             */
/*   Updated: 2020/08/05 18:19:27 by aollero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/parse_plholder.h"

int		get_type(const char **str, t_fplholder **plholder, t_list **arglist)
{
	char	i;
	t_args	*aux;

	if ((i = char_in_base(*(*str), "cspdiuxX%")) != -1)
	{
		(*plholder)->type = i;
		if (i != 8)
		{
			if (app_lst(arglist, (void *(*)(void))&arg_alloc, LST_ORDER))
				return (1);
			aux = ((t_args *)((t_list *)blst(*arglist, LST_ORDER))->content);
			aux->type = i;
			(*plholder)->arg = aux;
			(*plholder)->is_arg = 1;
		}
		(*plholder)->is_out = 0;
	}
	if (*(*str))
		(*str)++;
	return (0);
}

int		parse_prec(const char **str, t_fplholder **phold, t_list **args)
{
	while (*(*str) == '.')
		(*str)++;
	if (*(*str) == '*')
	{
		(*str)++;
		if (app_lst(args, (void *(*)(void))&arg_alloc, LST_ORDER))
			return (1);
		free((*phold)->prectms);
		(*phold)->prectms = &(((t_args *)((t_list *)blst(*args,
										LST_ORDER))->content)->param.nbr);
		((t_args *)((t_list *)blst(*args, LST_ORDER))->content)->type = 9;
		(*phold)->has_varprec = 1;
		(*phold)->arg = (t_args *)((t_list *)blst(*args, LST_ORDER))->content;
		(*phold)->is_out = -1;
		(*phold)->is_arg = 1;
		return (0);
	}
	else if (ft_isdigit(*(*str)))
	{
		*(*phold)->prectms = ft_atoi((*str));
		(*str) += nbr_len(*(*phold)->prectms, 10);
		return (0);
	}
	*(*phold)->prectms = 0;
	return (0);
}

void	parse_flg(const char **str, t_fplholder **plholder)
{
	while (*(*str) == '-' || *(*str) == '0')
	{
		if (*(*str) == '0' && (*plholder)->flag != 1)
			(*plholder)->flag = 2;
		if (*(*str) == '-')
			(*plholder)->flag = 1;
		if (*(*str))
			(*str)++;
	}
}

int		parse_width(const char **str, t_fplholder **plholder,
						t_list **arglist)
{
	t_args *aux;

	parse_flg(str, plholder);
	if (*(*str) == '*')
	{
		(*str)++;
		if (app_lst(arglist, (void *(*)(void))&arg_alloc, LST_ORDER))
			return (1);
		aux = (t_args *)((t_list *)blst(*arglist, LST_ORDER))->content;
		free((*plholder)->wthtms);
		(*plholder)->wthtms = &aux->param.nbr;
		(*plholder)->arg = aux;
		(*plholder)->is_out = -1;
		(*plholder)->has_varwth = 1;
		aux->type = 9;
		(*plholder)->is_arg = 1;
	}
	else if (ft_isdigit(*(*str)))
	{
		*(*plholder)->wthtms = ft_atoi((*str));
		(*str) += nbr_len(*(*plholder)->wthtms, 10);
	}
	return (0);
}

int		parse_plholder(const char **str, t_fplholder **plholder,
									t_list **arglist)
{
	(*plholder)->startptr = *str;
	if (!*((*str) + 1) || *(*str)++ != '%')
		return (2);
	if (ft_isdigit(*(*str)) || *(*str) == '-' || *(*str) == '*')
		parse_width(str, plholder, arglist);
	if (*(*str) == '.')
		parse_prec(str, plholder, arglist);
	if ((char_in_base(*(*str), "cspdiuxX%")) != -1)
		get_type(str, plholder, arglist);
	else if ((*plholder)->type == -2 && is_strinstr((*str), "cspdiuxX%"))
	{
		*str = is_strinstr((*str), "cspdiuxX%");
		if ((char_in_base(*((*str) - 1), "cspdiuxX%")) != -1 && (*str)--)
			get_type(str, plholder, arglist);
	}
	(*plholder)->endptr = *str;
	return (0);
}
