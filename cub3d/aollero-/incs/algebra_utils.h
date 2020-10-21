/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algebra_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollero- <aollero@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 10:48:18 by aollero-          #+#    #+#             */
/*   Updated: 2020/10/12 10:51:41 by aollero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGEBRA_UTILS_H
# define ALGEBRA_UTILS_H
# include "cubconf.h"
# include <math.h>

double	ft_distance(t_point *a, t_point *b);
void	keyswap(t_pdist **a, t_pdist **b);
void	rot2vect2(double *vector1[2], double *vector2[2], double angle);
void	norm_vector(double (*vector)[2], double len);
void	move_point(double *point[2], double vector[2]);

#endif
