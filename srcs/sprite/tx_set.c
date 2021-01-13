/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tx_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 10:52:38 by plam              #+#    #+#             */
/*   Updated: 2021/01/13 00:40:32 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	wall_set_bis(t_a *a)
{
	a->ntx.img = (int *)mlx_get_data_addr(a->ntx.ptr,
			&a->ntx.bpp, &a->ntx.size_l, &a->ntx.endian);
	if (a->ntx.img == NULL)
		error(MALLOC_FAIL_NO, a);
	a->stx.img = (int *)mlx_get_data_addr(a->stx.ptr,
			&a->stx.bpp, &a->stx.size_l, &a->stx.endian);
	if (a->stx.img == NULL)
		error(MALLOC_FAIL_SO, a);
	a->etx.img = (int *)mlx_get_data_addr(a->etx.ptr,
			&a->etx.bpp, &a->wtx.size_l, &a->etx.endian);
	if (a->etx.img == NULL)
		error(MALLOC_FAIL_EA, a);
	a->wtx.img = (int *)mlx_get_data_addr(a->wtx.ptr,
			&a->wtx.bpp, &a->etx.size_l, &a->wtx.endian);
	if (a->wtx.img == NULL)
		error(MALLOC_FAIL_WE, a);
}

void	wall_set(t_a *a)
{
	a->tex.dim = 64;
	a->ntx.ptr = mlx_xpm_file_to_image(a->mlx.ptr, a->txr.n,
			&a->tex.dim, &a->tex.dim);
	if (a->ntx.ptr == NULL)
		error(MALLOC_FAIL_NO, a);
	a->stx.ptr = mlx_xpm_file_to_image(a->mlx.ptr, a->txr.s,
			&a->tex.dim, &a->tex.dim);
	if (a->stx.ptr == NULL)
		error(MALLOC_FAIL_SO, a);
	a->etx.ptr = mlx_xpm_file_to_image(a->mlx.ptr, a->txr.e,
			&a->tex.dim, &a->tex.dim);
	if (a->etx.ptr == NULL)
		error(MALLOC_FAIL_EA, a);
	a->wtx.ptr = mlx_xpm_file_to_image(a->mlx.ptr, a->txr.w,
			&a->tex.dim, &a->tex.dim);
	if (a->etx.ptr == NULL)
		error(MALLOC_FAIL_WE, a);
	wall_set_bis(a);
}

void	sprite_set(t_a *a)
{
	a->spr.z_buff = malloc(sizeof(double) * (a->res.w + 1));
	if (a->spr.z_buff == NULL)
		error(-1, a);
	a->spr.dist = malloc(sizeof(double) * (a->spr.amount + 1));
	if (a->spr.dist == NULL)
		error(-1, a);
	a->spr.dist[a->spr.amount] = '\0';
	a->spr.order = malloc(sizeof(int) * (a->spr.amount + 1));
	if (a->spr.order == NULL)
		error(-1, a);
	a->spr.order[a->spr.amount] = '\0';
	a->spr_txr.ptr = mlx_xpm_file_to_image(a->mlx.ptr, a->txr.spr,
			&a->tex.dim, &a->tex.dim);
	if (a->spr_txr.ptr == NULL)
		error(-1, a);
	a->spr_txr.img = (int *)mlx_get_data_addr(a->spr_txr.ptr,
			&a->spr_txr.bpp, &a->spr_txr.size_l, &a->spr_txr.endian);
	if (a->spr_txr.img == NULL)
		error(-1, a);
}

int	tx_set(t_a *a)
{
	a->ntx.ptr = mlx_xpm_file_to_image(a->mlx.ptr, a->txr.n, &a->tex.dim,
			&a->tex.dim);
	a->stx.ptr = mlx_xpm_file_to_image(a->mlx.ptr, a->txr.s, &a->tex.dim,
			&a->tex.dim);
	a->etx.ptr = mlx_xpm_file_to_image(a->mlx.ptr, a->txr.e, &a->tex.dim,
			&a->tex.dim);
	a->wtx.ptr = mlx_xpm_file_to_image(a->mlx.ptr, a->txr.w, &a->tex.dim,
			&a->tex.dim);
	if (a->ntx.ptr == 0 || a->stx.ptr == 0 || a->etx.ptr == 0
		|| a->wtx.ptr == 0)
		return (ERR);
	a->ntx.img = (int *)mlx_get_data_addr(a->ntx.ptr, &a->ntx.bpp,
			&a->ntx.size_l, &a->ntx.endian);
	a->stx.img = (int *)mlx_get_data_addr(a->stx.ptr, &a->stx.bpp,
			&a->stx.size_l, &a->stx.endian);
	a->etx.img = (int *)mlx_get_data_addr(a->etx.ptr, &a->etx.bpp,
			&a->wtx.size_l, &a->etx.endian);
	a->wtx.img = (int *)mlx_get_data_addr(a->wtx.ptr, &a->wtx.bpp,
			&a->etx.size_l, &a->wtx.endian);
	if (a->ntx.img == 0 || a->stx.img == 0 || a->etx.img == 0
		|| a->wtx.img == 0)
		return (ERR);
	return (OK);
}
