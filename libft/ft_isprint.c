/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollero- <aollero@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 17:21:53 by aollero-          #+#    #+#             */
/*   Updated: 2020/06/29 17:22:03 by aollero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isprint(int c)
{
	if (' ' <= c && c < 127)
		return (1);
	else
		return (0);
}
