/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_mv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 22:02:03 by plam              #+#    #+#             */
/*   Updated: 2021/01/11 10:38:22 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mv_fw(t_a *a)
{
	if (a->mov.mov[FW] == OK)
	{
		if (a->map.map[(int)a->plr.pos_y]
			[(int)(a->plr.pos_x + a->dir.x * a->plr.move_spd)] != '1'
			&& a->map.map[(int)a->plr.pos_y]
			[(int)(a->plr.pos_x + a->dir.x * a->plr.move_spd)] != '2')
			a->plr.pos_x += a->dir.x * a->plr.move_spd;
		if (a->map.map[(int)(a->plr.pos_y + a->dir.y * a->plr.move_spd)]
			[(int)a->plr.pos_x] != '1'
			&& a->map.map[(int)(a->plr.pos_y + a->dir.y * a->plr.move_spd)]
			[(int)a->plr.pos_x] != '2')
			a->plr.pos_y += a->dir.y * a->plr.move_spd;
	}
}

void	mv_bw(t_a *a)
{
	if (a->mov.mov[BW] == OK)
	{
		if (a->map.map[(int)a->plr.pos_y]
			[(int)(a->plr.pos_x - a->dir.x * a->plr.move_spd)] != '1'
			&& a->map.map[(int)a->plr.pos_y]
			[(int)(a->plr.pos_x - a->dir.x * a->plr.move_spd)] != '2')
			a->plr.pos_x -= a->dir.x * a->plr.move_spd;
		if (a->map.map[(int)(a->plr.pos_y - a->dir.y * a->plr.move_spd)]
			[(int)a->plr.pos_x] != '1'
			&& a->map.map[(int)(a->plr.pos_y - a->dir.y * a->plr.move_spd)]
			[(int)a->plr.pos_x] != '2')
			a->plr.pos_y -= a->dir.y * a->plr.move_spd;
	}
}

void	mv_l(t_a *a)
{
	if (a->mov.mov[L] == OK)
	{
		if (a->map.map[(int)a->plr.pos_y]
			[(int)(a->plr.pos_x - a->dir.plane_x * a->plr.move_spd)] != '1'
			&& a->map.map[(int)a->plr.pos_y]
			[(int)(a->plr.pos_x - a->dir.plane_x * a->plr.move_spd)] != '2')
			a->plr.pos_x -= a->dir.plane_x * a->plr.move_spd;
		if (a->map.map[(int)(a->plr.pos_y - a->dir.plane_y * a->plr.move_spd)]
			[(int)a->plr.pos_x] != '1'
			&& a->map.map[(int)(a->plr.pos_y - a->dir.plane_y * a->plr.move_spd)]
			[(int)a->plr.pos_x] != '2')
			a->plr.pos_y -= a->dir.plane_y * a->plr.move_spd;
	}
}

void	mv_r(t_a *a)
{
	if (a->mov.mov[R] == OK)
	{
		if (a->map.map[(int)a->plr.pos_y]
			[(int)(a->plr.pos_x + a->dir.plane_x * a->plr.move_spd)] != '1'
			&& a->map.map[(int)a->plr.pos_y]
			[(int)(a->plr.pos_x + a->dir.plane_x * a->plr.move_spd)] != '2')
			a->plr.pos_x += a->dir.plane_x * a->plr.move_spd;
		if (a->map.map[(int)(a->plr.pos_y + a->dir.plane_y * a->plr.move_spd)]
			[(int)a->plr.pos_x] != '1'
			&& a->map.map[(int)(a->plr.pos_y + a->dir.plane_y * a->plr.move_spd)]
			[(int)a->plr.pos_x] != '2')
			a->plr.pos_y += a->dir.plane_y * a->plr.move_spd;
	}
}
