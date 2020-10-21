/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_rm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollero- <aollero@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 11:26:48 by aollero-          #+#    #+#             */
/*   Updated: 2020/07/30 13:33:41 by aollero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/lst_rm.h"

void	pl_del(void *fplhold)
{
	t_fplholder *auxphol;

	auxphol = (t_fplholder *)fplhold;
	if (!auxphol->has_varprec)
		free(auxphol->prectms);
	if (!auxphol->has_varwth)
		free(auxphol->wthtms);
	free(auxphol);
}

void	arg_del(void *arg)
{
	t_args *auxarg;

	auxarg = (t_args *)arg;
	free(auxarg);
}

void	out_del(void *output)
{
	t_out *auxout;

	auxout = (t_out *)output;
	free(*(auxout->str));
	free(auxout);
}
