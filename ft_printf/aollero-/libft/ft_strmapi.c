/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollero- <aollero@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 17:33:51 by aollero-          #+#    #+#             */
/*   Updated: 2020/06/29 17:34:06 by aollero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*resul;

	resul = malloc(sizeof(*s) * ft_strlen(s) + 1);
	if (resul == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		resul[i] = (*f)(i, s[i]);
		i++;
	}
	resul[i] = '\0';
	return (resul);
}
