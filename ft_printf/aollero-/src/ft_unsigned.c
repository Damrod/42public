/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollero- <aollero@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 14:22:08 by aollero-          #+#    #+#             */
/*   Updated: 2020/08/05 11:58:40 by aollero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_unsigned.h"
#include "../incs/misc2.h"
#include "../incs/libft.h"

char					*ft_lutoa_base(unsigned long long int nbr,
												const char *base)
{
	char				*res;
	size_t				len;
	size_t				baselen;

	baselen = ft_strlen(base);
	len = unbr_len(nbr, baselen);
	if (!is_base_valid(base))
		return (NULL);
	if (!(res = ft_calloc(sizeof(char), (len + 1))))
		return (NULL);
	while (len > 0)
	{
		len--;
		*(res + len) = *(base + (nbr % baselen));
		nbr /= baselen;
	}
	return (res);
}

char					*ft_utoa_base(unsigned int nbr, const char *base)
{
	char				*res;
	size_t				len;
	size_t				baselen;

	baselen = ft_strlen(base);
	len = unbr_len(nbr, baselen);
	if (!is_base_valid(base))
		return (NULL);
	if (!(res = ft_calloc(sizeof(char), (len + 1))))
		return (NULL);
	while (len > 0)
	{
		len--;
		*(res + len) = *(base + (nbr % baselen));
		nbr /= baselen;
	}
	return (res);
}
