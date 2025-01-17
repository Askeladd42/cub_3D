/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 23:50:45 by plam              #+#    #+#             */
/*   Updated: 2021/01/10 22:13:05 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_txr(t_a *a)
{
	a->txr.f_rgb = -1;
	a->txr.c_rgb = -1;
	a->txr.n = 0;
	a->txr.s = 0;
	a->txr.w = 0;
	a->txr.e = 0;
	a->txr.spr = 0;
	a->txr.f = 0;
	a->txr.c = 0;
}

void	init_dir(t_a *a)
{
	a->dir.plane_x = 0;
	a->dir.plane_y = 0;
	a->dir.x = 0;
	a->dir.y = 0;
}

void	init_plr(t_a *a)
{
	a->plr.pos_x = -1;
	a->plr.pos_y = -1;
	a->plr.move_spd = 0.04;
	a->plr.rot_spd = 0.024;
}

void	init_mov(t_a *a)
{
	a->mov.mov[ESC] = FALSE;
	a->mov.mov[FW] = FALSE;
	a->mov.mov[BW] = FALSE;
	a->mov.mov[L] = FALSE;
	a->mov.mov[R] = FALSE;
	a->mov.mov[LR] = FALSE;
	a->mov.mov[RR] = FALSE;
}

void	init(t_a *a)
{
	a->mlx.ptr = NULL;
	a->mlx.win = NULL;
	a->img.img_ptr = NULL;
	a->res.h = 0;
	a->res.w = 0;
	init_txr(a);
	init_plr(a);
	a->map.map = 0;
	a->map.m_cp = 0;
	a->map.x = 0;
	a->map.y = 0;
	a->map.first = NULL;
	a->map.lst = NULL;
	init_dir(a);
	init_mov(a);
	init_wall(a);
	init_spr(a);
	a->bmp.fd = 0;
	a->mlx.ptr = mlx_init();
	if (a->mlx.ptr == NULL)
		error(MLX_INIT_FAIL, a);
	a->mlx.line = malloc(sizeof(char **));
	if (a->mlx.line == NULL)
		error(MALLOC_FAIL_LINE, a);
}
