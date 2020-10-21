/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollero- <aollero@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 16:57:35 by aollero-          #+#    #+#             */
/*   Updated: 2020/08/05 18:17:35 by aollero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/misc2.h"

size_t		nbr_len(long long int nbr, const size_t baselen)
{
	size_t	len;

	len = 0;
	if (nbr < 0)
		len = 1;
	while (len < 66)
	{
		len++;
		if (nbr / (int)baselen == 0)
			break ;
		nbr /= baselen;
	}
	return (len);
}

size_t		unbr_len(unsigned long long int nbr, const size_t baselen)
{
	size_t	len;

	len = 0;
	while (1)
	{
		len++;
		if (nbr / baselen == 0)
			break ;
		nbr /= baselen;
	}
	return (len);
}

int			is_base_valid(const char *base)
{
	const char	*aux;
	int			j;
	int			k;

	aux = base;
	if (ft_strlen(base) < 2)
		return (0);
	k = 0;
	while (base[k] != '\0')
	{
		if (base[k] == '\t' || base[k] == '\n' || base[k] == '\v'
			|| base[k] == '\f' || base[k] == '\r' || base[k] == ' '
			|| base[k] == '+' || base[k] == '-')
			return (0);
		j = k;
		while (aux[j] != '\0')
		{
			if (aux[j] == base[k] && j != k)
				return (0);
			j++;
		}
		k++;
	}
	return (1);
}

int			char_in_base(char c, const char *base)
{
	int		i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

char		*is_strinstr(const char *str, const char *charset)
{
	int				i;
	char			*join;

	if (!(join = ft_strjoin("0123456789.*%", charset)))
		return (NULL);
	i = 0;
	while (*(str + i) && ft_strchr(join, *(str + i)))
	{
		if (ft_strchr(charset, *(str + i)))
		{
			i++;
			break ;
		}
		i++;
	}
	free(join);
	return ((char*)(str + i));
}
