/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_isvalid.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollero- <aollero@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 16:09:09 by aollero-          #+#    #+#             */
/*   Updated: 2020/10/11 22:53:22 by aollero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_ISVALID_H
# define PARSE_ISVALID_H
# include "../libft/libft.h"

int		is_inside(char c);
int		isvalidchr(char c);
int		isbeginvalid(char *line);
int		is2chrvalid(char a, char b);
int		iscolvalid(t_array *array, size_t j);

#endif
