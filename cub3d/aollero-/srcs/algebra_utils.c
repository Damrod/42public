/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollero- <aollero@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 10:45:35 by aollero-          #+#    #+#             */
/*   Updated: 2020/10/12 10:52:56 by aollero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/algebra_utils.h"

double	ft_distance(t_point *a, t_point *b)
{
	double aux;

	aux = sqrt(pow(a->x - b->x, 2) + pow(a->y - b->y, 2));
	return (aux);
}

void	keyswap(t_pdist **a, t_pdist **b)
{
	t_pdist *temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	rot2vect2(double *vector1[2], double *vector2[2], double angle)
{
	rotvect2(vector1, 1, angle);
	rotvect2(vector2, 1, angle);
}

void	norm_vector(double (*vector)[2], double len)
{
	double aux;

	aux = sqrt(pow((*vector)[0], 2) + pow((*vector)[1], 2));
	(*vector)[0] *= (len / aux);
	(*vector)[1] *= (len / aux);
}

void	move_point(double *point[2], double vector[2])
{
	*point[0] += vector[0];
	*point[1] += vector[1];
}
