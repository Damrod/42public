/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_cat.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollero- <aollero@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 19:06:50 by aollero-          #+#    #+#             */
/*   Updated: 2020/08/05 19:10:55 by aollero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OUT_CAT_H
# define OUT_CAT_H

# include "out_format.h"
# include "lst_alloc.h"
# include "parse_fstr.h"

int			out_types(t_fplholder *plholder, t_out *out);
int			createoutput(t_list *plholders, t_list **output);
size_t		totlen(t_list *output);
t_restot	*cr_restot(t_list *output);
int			catoutput(t_list *output);
#endif
