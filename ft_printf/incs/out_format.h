/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_format.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollero- <aollero@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 18:43:33 by aollero-          #+#    #+#             */
/*   Updated: 2020/08/05 19:01:12 by aollero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OUT_FORMAT_H
# define OUT_FORMAT_H

# include "ft_printf.h"
# include "ft_unsigned.h"
# include "misc.h"

char	*get_base(enum e_types type);
char	*ft_itox(void *nbr, enum e_types type);
char	*setfield(t_fplholder *phold, t_args *arg);
char	*nb_setfield(t_fplholder *phold, t_args *arg);
char	*nb_precfield(t_fplholder *phold, t_args *arg);
char	*setptr(t_fplholder *phold, t_args *arg);
char	*ft_itox2(t_args *arg);
char	*setnbr(t_fplholder *phold, t_args *arg);
char	*setsubstr(t_fplholder *phold, t_args *arg);
void	swapzeroes(char *str);
void	alignsub2field(char **field, char **substr, enum e_flags flag,
												t_fplholder *phold);
void	get_out(t_fplholder *phold, t_out *out, char *result);
int		out_str(t_fplholder *phold, t_out *out, t_args *arg);
int		out_ptr(t_fplholder *phold, t_out *out, t_args *arg);
int		out_nbr(t_fplholder *phold, t_out *out, t_args *arg);
#endif
