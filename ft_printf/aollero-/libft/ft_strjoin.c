/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollero- <aollero@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 17:30:21 by aollero-          #+#    #+#             */
/*   Updated: 2020/06/29 17:31:40 by aollero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*resul;
	size_t	i;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	resul = malloc(sizeof(*resul) * (len1 + len2) + 1);
	if (resul == NULL)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		resul[i] = s1[i];
		i++;
	}
	while (i < len1 + len2)
	{
		resul[i] = s2[i - len1];
		i++;
	}
	resul[i] = '\0';
	return (resul);
}
