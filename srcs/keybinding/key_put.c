/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_put.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 14:18:03 by plam              #+#    #+#             */
/*   Updated: 2021/01/11 10:39:56 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press(int key, t_a *a)
{
	a->mov.mov[key] = OK;
	return (OK);
}

int	key_release(int key, t_a *a)
{
	a->mov.mov[key] = FALSE;
	return (OK);
}

void	l_rot(t_a *a)
{
	if (a->mov.mov[LR] == OK)
	{
		a->dir.old_x = a->dir.x;
		a->dir.x = a->dir.x * cos(-a->plr.rot_spd)
			- a->dir.y * sin(-a->plr.rot_spd);
		a->dir.y = a->dir.old_x * sin(-a->plr.rot_spd)
			+ a->dir.y * cos(-a->plr.rot_spd);
		a->dir.oldplane_x = a->dir.plane_x;
		a->dir.plane_x = a->dir.plane_x * cos(-a->plr.rot_spd)
			- a->dir.plane_y * sin(-a->plr.rot_spd);
		a->dir.plane_y = a->dir.oldplane_x * sin(-a->plr.rot_spd)
			+ a->dir.plane_y * cos(-a->plr.rot_spd);
	}
}

void	r_rot(t_a *a)
{
	if (a->mov.mov[RR] == OK)
	{
		a->dir.old_x = a->dir.x;
		a->dir.x = a->dir.x * cos(a->plr.rot_spd)
			- a->dir.y * sin(a->plr.rot_spd);
		a->dir.y = a->dir.old_x * sin(a->plr.rot_spd)
			+ a->dir.y * cos(a->plr.rot_spd);
		a->dir.oldplane_x = a->dir.plane_x;
		a->dir.plane_x = a->dir.plane_x * cos(a->plr.rot_spd)
			- a->dir.plane_y * sin(a->plr.rot_spd);
		a->dir.plane_y = a->dir.oldplane_x * sin(a->plr.rot_spd)
			+ a->dir.plane_y * cos(a->plr.rot_spd);
	}
}

int	key_move(t_a *a)
{
	if (a->mov.mov[ESC] == OK)
		destroy(a);
	mv_fw(a);
	mv_bw(a);
	mv_l(a);
	mv_r(a);
	l_rot(a);
	r_rot(a);
	return (OK);
}
