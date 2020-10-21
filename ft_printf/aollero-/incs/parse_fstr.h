/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fstr.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollero- <aollero@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 18:34:43 by aollero-          #+#    #+#             */
/*   Updated: 2020/08/05 18:38:43 by aollero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_FSTR_H
# define PARSE_FSTR_H

# include "ft_printf.h"
# include "lst_alloc.h"
# include "parse_plholder.h"

int		handle_plhold(const char **str, t_list **arglist, t_list **plholders);
void	out_strlit(t_fplholder *plhold, const char *start, char *resul);
int		handle_strlit(const char **str, t_list **plholders, int *dowhile);
t_list	*parse_format(const char *str, t_list **arglist);
int		out_char(t_fplholder *phold, t_out *out, t_args *arg, char bool_perc);
#endif
