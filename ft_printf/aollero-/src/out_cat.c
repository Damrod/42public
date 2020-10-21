/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_cat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollero- <aollero@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 19:06:50 by aollero-          #+#    #+#             */
/*   Updated: 2020/08/05 19:11:36 by aollero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/out_cat.h"

int			out_types(t_fplholder *plholder, t_out *out)
{
	if (plholder->is_out == 1 || plholder->type == -1)
	{
		out->str = &plholder->res;
		out->len = &plholder->res_len;
		return (0);
	}
	else if (plholder->is_out == 0 && plholder->type == 0)
		return (out_char(plholder, out, plholder->arg, 0));
	else if (plholder->is_out == 0 && plholder->type == 1)
		return (out_str(plholder, out, plholder->arg));
	else if (plholder->is_out == 0 && plholder->type == 2)
		return (out_ptr(plholder, out, plholder->arg));
	else if (plholder->is_out == 0 && (plholder->type == 3 ||
		plholder->type == 4 || plholder->type == 5 ||
		plholder->type == 6 || plholder->type == 7))
		return (out_nbr(plholder, out, plholder->arg));
	else if (plholder->is_out == 0 && plholder->type == 8)
		return (out_char(plholder, out, NULL, 1));
	else
		return (1);
}

int			createoutput(t_list *plholders, t_list **output)
{
	t_fplholder	*auxplh;
	t_out		*aux;

	while (plholders)
	{
		auxplh = ((t_fplholder *)(plholders)->content);
		if (auxplh->is_out != -1)
		{
			if (app_lst(output, (void *(*)(void))&out_alloc, LST_ORDER))
				return (1);
			aux = ((t_out *)((t_list *)blst(*output, LST_ORDER))->content);
			if (out_types(auxplh, aux))
				return (1);
		}
		(plholders) = (plholders)->next;
	}
	return (0);
}

size_t		totlen(t_list *output)
{
	size_t	len;

	len = 0;
	while (output)
	{
		len += *((t_out *)(output->content))->len;
		output = output->next;
	}
	return (len);
}

t_restot	*cr_restot(t_list *output)
{
	t_restot	*restot;
	char		*strstart;
	int			flg;

	if (!(restot = malloc(sizeof(*restot))))
		return (NULL);
	restot->len = totlen(output);
	if (!(restot->str = ft_calloc(sizeof(char), restot->len + 1)))
	{
		free(restot);
		return (NULL);
	}
	strstart = restot->str;
	while (output)
	{
		flg = (((size_t)*((t_out *)(output->content))->len !=
				ft_strlen(*((t_out *)(output->content))->str)) ? 0 : 1);
		ft_wrtptr(restot->str, *((t_out *)(output->content))->str,
							*((t_out *)(output->content))->len, flg);
		restot->str += *((t_out *)(output->content))->len;
		output = output->next;
	}
	restot->str = strstart;
	return (restot);
}

int			catoutput(t_list *output)
{
	t_restot	*restot;
	long int	ret_val;

	if (!(restot = cr_restot(output)))
		return (-1);
	ret_val = write(1, restot->str, restot->len);
	free(restot->str);
	free(restot);
	return ((int)ret_val);
}
