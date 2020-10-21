/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_format2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollero- <aollero@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 18:59:18 by aollero-          #+#    #+#             */
/*   Updated: 2020/08/05 19:00:02 by aollero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/out_format.h"

void	alignsub2field(char **field, char **substr, enum e_flags flag,
														t_fplholder *phold)
{
	char		*aux;

	if (*(phold->prectms) <= *(phold->wthtms))
	{
		if (flag == 0 || flag == 2)
			ft_wrtstr_alright(*field, *substr, ft_strlen(*substr));
		else
			ft_wrtptr(*field, *substr, ft_strlen(*substr), 1);
		free(*substr);
	}
	else
	{
		aux = *field;
		*field = *substr;
		free(aux); //doesn't it break when substr == (null)?
		return ;
	}
}

void	get_out(t_fplholder *phold, t_out *out, char *result)
{
	phold->is_out = 1;
	phold->res = result;
	phold->res_len = ft_strlen(result);
	out->len = &phold->res_len;
	out->str = &phold->res;
	return ;
}

int		out_str(t_fplholder *phold, t_out *out, t_args *arg)
{
	char	*field;
	char	*substr;
	int		strnull;

	strnull = 0;
	if (!arg->param.str)
	{
		if (!(arg->param.str = ft_strdup("(null)")))
			return (1);
		strnull = 1;
	}
	if (!(field = setfield(phold, arg)))
		return (1);
	if (!(substr = setsubstr(phold, arg)))
		return (1);
	alignsub2field(&field, &substr, phold->flag, phold);
	get_out(phold, out, field);
	if (strnull)
		free(arg->param.str);
	return (0);
}

int		out_ptr(t_fplholder *phold, t_out *out, t_args *arg)
{
	char *field;
	char *substr;

	if (!(substr = setptr(phold, arg)))
		return (1);
	if (!(field = setfield(phold, arg)))
		return (1);
	alignsub2field(&field, &substr, phold->flag, phold);
	get_out(phold, out, field);
	return (0);
}

int		out_nbr(t_fplholder *phold, t_out *out, t_args *arg)
{
	char *field;
	char *substr;
	char *precfield;

	if (!(substr = setnbr(phold, arg)))
		return (1);
	if (!(field = nb_setfield(phold, arg)))
		return (1);
	if (!(precfield = nb_precfield(phold, arg)))
		return (1);
	alignsub2field(&field, &precfield, phold->flag, phold);
	get_out(phold, out, field);
	swapzeroes(phold->res);
	return (0);
}
