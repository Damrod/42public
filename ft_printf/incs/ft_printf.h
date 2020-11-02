/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollero- <aollero@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 16:37:03 by aollero-          #+#    #+#             */
/*   Updated: 2020/08/05 01:48:28 by aollero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include "libft.h"

/*
** LST_ORDER 1 list add back
** LST_ORDER 0 list add front
*/

# ifndef LST_ORDER
#  define LST_ORDER 1
# endif

typedef unsigned long long int	t_lluint;

/*
** strlit = string literal
** c = char
** s = string
** p = pointer
** d = integer decimal
** i = signed integer
** u = unsigned integer
** x = integer hex lowercase
** X = integer hex uppercase
** var = variable argument count field ([*] flag)
**
** var type is outdated. It's not, it's useful in arglist.
** review usefulness of var type in pholders
** percent = %%
*/

enum				e_types{
	notype = -2,
	strlit = -1,
	c = 0,
	s = 1,
	p = 2,
	d = 3,
	i = 4,
	u = 5,
	x = 6,
	X = 7,
	percentlit = 8,
	var = 9
};

/*
** In the next enum e_flags:
** l = left alignment = '-'
** z = zero padding = '0'
** r = right alignment (default)
** n = it's not a flag
*/

enum				e_flags{
	n = 0,
	r = 0,
	l = 1,
	z = 2,
};

/*
** This union takes any one single parameter passed by stdargs
** of any type.
*/

typedef union		u_type{
	char			*str;
	void			*ptr;
	int				nbr;
	unsigned int	unbr;
}					t_types;

/*
** This list holds variables to take input from va_arg
*/

typedef struct		s_args{
	enum e_types	type;
	union u_type	param;
}					t_args;

/*
** This is a struct to store, after parsing the format string:
**	* format placeholders,
**	* string literals
**	* variable argument counts [*] for the flags
** default values should be:
** plholder->startptr = NULL;
** plholder->endptr = NULL;
** plholder->flag = 0;
** *plholder->wthtms = -1;
** has_varwth = 0;
** *plholder->prectms = -1;
** has_varprec = 0;
** plholder->type = -2;
** plholder->res = NULL;
** plholder->arg = NULL;
** plholder->res_len = -1;
** plholder->is_arg = -1;
** plholder->is_out = -1;
*/

typedef struct		s_format_placeholder{
	const char		*startptr;
	const char		*endptr;
	enum e_flags	flag;
	int				*wthtms;
	int				has_varwth;
	int				*prectms;
	int				has_varprec;
	enum e_types	type;
	char			*res;
	long int		res_len;
	int				is_arg;
	int				is_out;
	t_args			*arg;
}					t_fplholder;

/*
** This list will hold strings ready for output
*/

typedef struct		s_output{
	char			**str;
	long int		*len;
}					t_out;

/*
** This struct is not meant to be a list, just a place to store the total result
*/

typedef struct		s_restot{
	char			*str;
	long int		len;
}					t_restot;

int					ft_printf(const char *format, ...);

#endif
