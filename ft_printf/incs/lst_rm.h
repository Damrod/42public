/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_rm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollero- <aollero@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 11:47:03 by aollero-          #+#    #+#             */
/*   Updated: 2020/08/05 19:32:53 by aollero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_RM_H
# define LST_RM_H
# include "ft_printf.h"
# include "misc.h"

void		pl_del(void *plhold);
void		arg_del(void *arg);
void		out_del(void *output);
#endif
