/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spr_cfg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 22:44:49 by plam              #+#    #+#             */
/*   Updated: 2021/01/12 23:57:31 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_spr(t_a *a)
{
	a->spr_txr.ptr = 0;
	a->spr.pos_x = 0;
	a->spr.pos_y = 0;
	a->spr.z_buff = 0;
	a->spr.dist = 0;
	a->spr.order = 0;
}

void	sprite_count(t_a *a)
{
	int	y;
	int	x;

	y = 0;
	a->spr.amount = 0;
	while (a->map.map[y])
	{
		x = 0;
		while (a->map.map[y][x])
		{
			if (a->map.map[y][x] == '2')
				a->spr.amount++;
			x++;
		}
		y++;
	}
}

void	sprite_pos(t_a *a)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	y = 0;
	while (a->map.map[y])
	{
		x = 0;
		while (a->map.map[y][x])
		{
			if (a->map.map[y][x] == '2')
			{
				a->spr.pos_x[i] = x + 0.5;
				a->spr.pos_y[i] = y + 0.5;
				i++;
			}
			x++;
		}
		y++;
	}
	a->spr.pos_x[i] = '\0';
	a->spr.pos_y[i] = '\0';
}

void	sprite_list(t_a *a)
{
	sprite_count(a);
	a->spr.pos_x = malloc(sizeof(double) * (a->spr.amount + 1));
	if (a->spr.pos_x == NULL)
		error(MALLOC_FAIL_SPR, a);
	a->spr.pos_y = malloc(sizeof(double) * (a->spr.amount + 1));
	if (a->spr.pos_y == NULL)
		error(MALLOC_FAIL_SPR, a);
	sprite_pos(a);
}
