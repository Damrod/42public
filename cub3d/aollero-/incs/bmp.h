/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollero- <aollero@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 16:22:55 by aollero-          #+#    #+#             */
/*   Updated: 2020/10/12 12:29:19 by aollero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BMP_H
# define BMP_H
# include "inttypes.h"

typedef struct __attribute__((__packed__))								s_bmp{
	uint16_t								bftype;
	uint32_t								bfsize;
	uint16_t								bfreserved1;
	uint16_t								bfreserved2;
	uint32_t								bfoffbits;
	uint32_t								bisize;
	uint32_t								biwidth;
	uint32_t								biheight;
	uint16_t								biplanes;
	uint16_t								bibitcount;
	uint32_t								bicompression;
	uint32_t								bisizeimage;
	uint32_t								bixpelspermeter;
	uint32_t								biypelspermeter;
	uint32_t								biclrused;
	uint32_t								biclrimportant;
}											t_bmp;

#endif
