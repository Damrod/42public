/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollero- <aollero@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 17:32:20 by aollero-          #+#    #+#             */
/*   Updated: 2020/06/29 18:48:23 by aollero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ischrinstr(const char c, const char *str)
{
	while (*str)
	{
		if (c == *str)
			return (1);
		str++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*resul;
	size_t	len;
	size_t	i;
	int		j;

	len = ft_strlen(s1);
	i = 0;
	while (ischrinstr(s1[i], set) && s1[i])
	{
		len--;
		i++;
	}
	j = ft_strlen(s1) - 1;
	while (ischrinstr(s1[j], set) && j >= 0)
	{
		len--;
		j--;
	}
	resul = ft_substr(s1, i, len);
	if (resul == NULL)
		return (NULL);
	return (resul);
}
