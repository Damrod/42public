/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollero- <aollero@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 16:03:13 by aollero-          #+#    #+#             */
/*   Updated: 2020/07/17 15:25:34 by aollero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlen(const char *s)
{
	char *dst;

	dst = (char *)s;
	while (*s)
		s++;
	return ((size_t)(s - dst));
}

char			*ft_strjoin(char const *s1, char const *s2)
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

char			*ft_strdup(const char *s)
{
	char	*des;
	int		i;

	des = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (des == NULL)
		return (NULL);
	i = 0;
	while (*(s + i) != '\0')
	{
		*(des + i) = *(s + i);
		i++;
	}
	*(des + i) = '\0';
	return (des);
}

char			*ft_strchr(const char *s, int c)
{
	char			*sou;
	unsigned int	i;

	sou = (char *)s;
	i = 0;
	while (sou[i] && sou[i] != (char)c)
		i++;
	if (i == ft_strlen(s) && c != '\0')
		return (NULL);
	else
		return ((char *)&sou[i]);
}
