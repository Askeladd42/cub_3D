/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   txr_malloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 23:20:43 by plam              #+#    #+#             */
/*   Updated: 2021/01/13 00:16:02 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	txr_malloc_bis(char c, int len, t_a *a)
{
	if (c == ' ')
	{
		a->txr.spr = malloc(sizeof(char) * len + 1);
		if (a->txr.spr == NULL)
			error(MALLOC_FAIL_TXR, a);
	}
	if (c == 'F')
	{
		a->txr.f = malloc(sizeof(char) * len + 1);
		if (a->txr.f == NULL)
			error(MALLOC_FAIL_TXR, a);
	}
	if (c == 'C')
	{
		a->txr.c = malloc(sizeof(char) * len + 1);
		if (a->txr.c == NULL)
			error(MALLOC_FAIL_TXR, a);
	}
}

void	txr_malloc(char c, int len, t_a *a)
{
	if (c == 'N')
	{
		a->txr.n = malloc(sizeof(char) * len + 1);
		if (a->txr.n == NULL)
			error(MALLOC_FAIL_TXR, a);
	}
	if (c == 'S')
	{
		a->txr.s = malloc(sizeof(char) * len + 1);
		if (a->txr.s == NULL)
			error(MALLOC_FAIL_TXR, a);
	}
	if (c == 'W')
	{
		a->txr.w = malloc(sizeof(char) * len + 1);
		if (a->txr.w == NULL)
			error(MALLOC_FAIL_TXR, a);
	}
	if (c == 'E')
	{
		a->txr.e = malloc(sizeof(char) * len + 1);
		if (a->txr.e == NULL)
			error(MALLOC_FAIL_TXR, a);
	}
	return (txr_malloc_bis(c, len, a));
}
