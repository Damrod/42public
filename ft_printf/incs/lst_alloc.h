/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_alloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollero- <aollero@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 11:44:15 by aollero-          #+#    #+#             */
/*   Updated: 2020/08/05 19:30:47 by aollero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_ALLOC_H
# define LST_ALLOC_H
# include "ft_printf.h"

t_fplholder		*pl_alloc(void);
t_args			*arg_alloc(void);
t_out			*out_alloc(void);
int				app_lst(t_list **list, void *(*alloc)(void), char bool_back);
#endif
