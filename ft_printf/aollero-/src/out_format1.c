/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_format1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollero- <aollero@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 18:54:49 by aollero-          #+#    #+#             */
/*   Updated: 2020/08/05 18:56:14 by aollero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/out_format.h"

char		*setptr(t_fplholder *phold, t_args *arg)
{
	char		*str;
	t_lluint	nbr;
	char		*aux;
	char		*prefix;

	nbr = ((t_lluint)(arg->param.ptr));
	if (!(prefix = ft_strdup("0x")))
		return (NULL);
	if (!(aux = ft_itox(&nbr, arg->type)))
		return (NULL);
	if (!(str = ft_strjoin(prefix, aux)))
		return (NULL);
	free(prefix);
	free(aux);
	phold->res = str;
	phold->res_len = ft_strlen(phold->res);
	return (str);
}

char		*ft_itox2(t_args *arg)
{
	char			*str;
	void			*nbr;
	union u_type	param;
	t_lluint		lnbr;

	str = NULL;
	nbr = NULL;
	param = arg->param;
	if (arg->type == 3 || arg->type == 4)
		nbr = &param.nbr;
	else if (arg->type == 5 || arg->type == 6 || arg->type == 7)
		nbr = &param.unbr;
	else if (arg->type == 2)
	{
		lnbr = (size_t)param.ptr;
		nbr = &lnbr;
	}
	if (nbr)
	{
		if (!(str = ft_itox(nbr, arg->type)))
			return (NULL);
	}
	return (str);
}

char		*setnbr(t_fplholder *phold, t_args *arg)
{
	char			*str;
	char			*aux;

	if (!(str = ft_itox2(arg)))
		return (NULL);
	if ((arg->type == 3 || arg->type == 4) && arg->param.nbr < 0)
	{
		if (!(aux = ft_strdup(str + 1)))
			return (NULL);
		free(str);
		str = aux;
	}
	phold->res = str;
	phold->res_len = ft_strlen(str);
	return (str);
}

char		*setsubstr(t_fplholder *phold, t_args *arg)
{
	int		prec;
	char	*field;
	size_t	strlen;
	char	*str;

	str = arg->param.str;
	prec = 0;
	strlen = ft_strlen(str);
	if (phold->type == 1)
		prec = (*(phold->prectms) < 0 ? (int)strlen : *(phold->prectms));
	prec = sm(prec, strlen);
	if (!(field = ft_calloc(sizeof(char), prec + 1)))
		return (NULL);
	ft_wrtptr(field, str, prec, 1);
	*(phold->prectms) = prec;
	return (field);
}

void		swapzeroes(char *str)
{
	char *minus;
	char *fstzero;

	fstzero = ft_strchr(str, '0');
	minus = ft_strchr(str, '-');
	if (fstzero && minus && fstzero < minus)
	{
		*fstzero = '-';
		*minus = '0';
	}
}
