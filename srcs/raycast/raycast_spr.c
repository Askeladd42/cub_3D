/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_spr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:13:31 by plam              #+#    #+#             */
/*   Updated: 2021/01/11 11:02:40 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sprite_height(t_a *a)
{
	a->spr.h = abs((int)(a->res.h / a->spr.transf_y));
	a->spr.px_start_y = -a->spr.h / 2 + a->res.h / 2;
	if (a->spr.px_start_y < 0)
		a->spr.px_start_y = 0;
	a->spr.px_end_y = a->spr.h / 2 + a->res.h / 2;
	if (a->spr.px_end_y >= a->res.h)
		a->spr.px_end_y = a->res.h - 1;
}

void	sprite_width(t_a *a)
{
	a->spr.w = abs((int)(a->res.h / a->spr.transf_y));
	a->spr.px_start_x = -a->spr.w / 2 + a->spr.screen_x;
	if (a->spr.px_start_x < 0)
		a->spr.px_start_x = 0;
	a->spr.px_end_x = a->spr.w / 2 + a->spr.screen_x;
	if (a->spr.px_end_x >= a->res.w)
		a->spr.px_end_x = a->res.w - 1;
}

void	sprite_raycast(t_a *a)
{
	int	i;

	i = 0;
	sprite_dist(a);
	sprite_sort(&a->spr);
	while (i < a->spr.amount)
	{
		a->spr.spr_x = a->spr.pos_x[a->spr.order[i]] - a->plr.pos_x;
		a->spr.spr_y = a->spr.pos_y[a->spr.order[i]] - a->plr.pos_y;
		a->spr.inv_det = 1.0 / (a->dir.plane_x * a->dir.y
				- a->dir.x * a->dir.plane_y);
		a->spr.transf_x = a->spr.inv_det * (a->dir.y * a->spr.spr_x
				- a->dir.x * a->spr.spr_y);
		a->spr.transf_y = a->spr.inv_det * (-a->dir.plane_y * a->spr.spr_x
				+ a->dir.plane_x * a->spr.spr_y);
		a->spr.screen_x = (int)((a->res.w / 2)
				*(1 + a->spr.transf_x / a->spr.transf_y));
		sprite_height(a);
		sprite_width(a);
		draw_sprite(a);
		i++;
	}
}
