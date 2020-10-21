/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plholder.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollero- <aollero@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 18:11:04 by aollero-          #+#    #+#             */
/*   Updated: 2020/08/05 19:33:45 by aollero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_PLHOLDER_H
# define PARSE_PLHOLDER_H

# include "ft_printf.h"
# include "misc.h"
# include "misc2.h"
# include "lst_alloc.h"

int		get_type(const char **str, t_fplholder **plholder, t_list **arglist);
int		parse_prec(const char **str, t_fplholder **phold, t_list **args);
void	parse_flg(const char **str, t_fplholder **plholder);
int		parse_width(const char **str, t_fplholder **plholder,
														t_list **arglist);
int		parse_plholder(const char **str, t_fplholder **plholder,
														t_list **arglist);
#endif
