/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollero- <aollero@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 17:02:22 by aollero-          #+#    #+#             */
/*   Updated: 2020/07/08 10:46:11 by aollero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	aux[n];
	unsigned char	*dst;
	unsigned char	*sou;
	unsigned int	i;

	if (!dest && !src)
		return (NULL);
	dst = (unsigned char *)dest;
	sou = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		aux[i] = sou[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		dst[i] = aux[i];
		i++;
	}
	return ((void *)dst);
}
