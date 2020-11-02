/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_format0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollero- <aollero@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 18:43:33 by aollero-          #+#    #+#             */
/*   Updated: 2020/08/05 18:49:25 by aollero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/out_format.h"

char		*get_base(enum e_types type)
{
	char	*base;

	base = NULL;
	if (type == 3 || type == 4 || type == 5)
	{
		if (!(base = ft_strdup("0123456789")))
			return (NULL);
	}
	if (type == 2 || type == 6)
	{
		if (!(base = ft_strdup("0123456789abcdef")))
			return (NULL);
	}
	if (type == 7)
	{
		if (!(base = ft_strdup("0123456789ABCDEF")))
			return (NULL);
	}
	return (base);
}

char		*ft_itox(void *nbr, enum e_types type)
{
	char	*base;
	char	*res;

	res = NULL;
	base = NULL;
	if (!(base = get_base(type)))
		return (NULL);
	if (type == 3 || type == 4)
		res = ft_itoa(*((int *)nbr));
	else if (type == 5 || type == 6 || type == 7)
		res = ft_utoa_base(*((unsigned int *)nbr), base);
	else if (type == 2)
		res = ft_lutoa_base(*((t_lluint *)nbr), base);
	free(base);
	return (res);
}

char		*setfield(t_fplholder *phold, t_args *arg)
{
	int		width;
	char	*field;
	char	mset;
	int		signsz;

	mset = (phold->flag == 2 ? '0' : ' ');
	signsz = ((arg->type == 3 || arg->type == 4) && arg->param.nbr < 0 ? 1 : 0);
	width = 1;
	if (phold->type == 2 || phold->type == 3 || phold->type == 4 ||
		phold->type == 5 || phold->type == 6 || phold->type == 7)
	{
		mset = ' ';
		width = gr(*(phold->wthtms), phold->res_len + signsz);
	}
	if (phold->type == 1)
		width = (*(phold->wthtms) == -1 ? (int)ft_strlen(arg->param.str) :
												*(phold->wthtms));
	if (!(field = ft_calloc(sizeof(char), width + 1)))
		return (NULL);
	ft_memset(field, mset, width);
	return (field);
}

char		*nb_setfield(t_fplholder *phold, t_args *arg)
{
	size_t	width;
	char	*field;
	char	mset;
	int		signsz;

	mset = (phold->flag == 2 && *phold->prectms == -1 ? '0' : ' ');
	signsz = ((arg->type == 3 || arg->type == 4) && arg->param.nbr < 0 ? 1 : 0);
	width = gr(*(phold->wthtms), phold->res_len + signsz);
	if (!(field = ft_calloc(sizeof(char), width + 1)))
		return (NULL);
	ft_memset(field, mset, width);
	return (field);
}

char		*nb_precfield(t_fplholder *phold, t_args *arg)
{
	size_t	prec;
	char	*field;
	int		signsz;

	signsz = ((arg->type == 3 || arg->type == 4) && arg->param.nbr < 0 ? 1 : 0);
	prec = gr(*(phold->prectms) + signsz, phold->res_len + signsz);
	if (arg->param.nbr == 0 && *phold->prectms == 0)
		return (ft_strdup(""));
	if (!(field = ft_calloc(sizeof(char), prec + 1)))
		return (NULL);
	ft_memset(field, '0', prec);
	ft_wrtstr_alright(field, phold->res, phold->res_len);
	if (signsz > 0)
		*field = '-';
	free(phold->res);
	phold->res = NULL;
	phold->res_len = -1;
	return (field);
}
