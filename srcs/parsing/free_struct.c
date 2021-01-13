/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 16:07:04 by plam              #+#    #+#             */
/*   Updated: 2021/01/06 09:43:38 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_txr(t_a *a)
{
	if (a->txr.n)
		free(a->txr.n);
	if (a->txr.s)
		free(a->txr.s);
	if (a->txr.w)
		free(a->txr.w);
	if (a->txr.e)
		free(a->txr.e);
	if (a->txr.spr)
		free(a->txr.spr);
	if (a->txr.f)
		free(a->txr.f);
	if (a->txr.c)
		free(a->txr.c);
	init_txr(a);
}

void	free_wall(t_a *a)
{
	if (a->ntx.ptr)
		mlx_destroy_image(a->mlx.ptr, a->ntx.ptr);
	if (a->stx.ptr)
		mlx_destroy_image(a->mlx.ptr, a->stx.ptr);
	if (a->etx.ptr)
		mlx_destroy_image(a->mlx.ptr, a->etx.ptr);
	if (a->wtx.ptr)
		mlx_destroy_image(a->mlx.ptr, a->wtx.ptr);
}

void	free_spr(t_a *a)
{
	if (a->spr_txr.ptr)
		mlx_destroy_image(a->mlx.ptr, a->spr_txr.ptr);
	if (a->spr.pos_x)
		free(a->spr.pos_x);
	if (a->spr.pos_y)
		free(a->spr.pos_y);
	if (a->spr.z_buff)
		free(a->spr.z_buff);
	if (a->spr.dist)
		free(a->spr.dist);
	if (a->spr.order)
		free(a->spr.order);
	init_spr(a);
}
