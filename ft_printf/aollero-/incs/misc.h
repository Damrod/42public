/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollero- <aollero@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 14:22:08 by aollero-          #+#    #+#             */
/*   Updated: 2020/08/05 19:31:08 by aollero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MISC_H
# define MISC_H
# include "libft.h"

long int	gr(long int a, long int b);
long int	sm(long int a, long int b);
void		ft_wrtptr(char *c, char *str, int size, int flg);
void		ft_wrtstr_alright(char *to, char *from, int size);
t_list		*blst(t_list *list, char bool_back);
#endif
