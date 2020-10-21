/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc2.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollero- <aollero@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 16:57:35 by aollero-          #+#    #+#             */
/*   Updated: 2020/08/05 18:18:46 by aollero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MISC2_H
# define MISC2_H
# include "ft_printf.h"

size_t			nbr_len(long long int nbr, const size_t baselen);
size_t			unbr_len(unsigned long long int nbr, const size_t baselen);
int				is_base_valid(const char *base);
int				char_in_base(char c, const char *base);
char			*is_strinstr(const char *str, const char *charset);
#endif
