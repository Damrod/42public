/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollero- <aollero@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 13:28:42 by aollero-          #+#    #+#             */
/*   Updated: 2020/07/28 13:43:52 by aollero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UNSIGNED_H
# define FT_UNSIGNED_H
# include "ft_printf.h"

char		*ft_lutoa_base(t_lluint nbr, const char *base);
char		*ft_utoa_base(unsigned int nbr, const char *base);
#endif
