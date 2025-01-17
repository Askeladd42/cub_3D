/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 16:57:40 by plam              #+#    #+#             */
/*   Updated: 2021/01/10 23:55:42 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_ceiling(t_a *a)
{
	int		y;
	int		pos;

	y = 0;
	while (y < a->img.px_start)
	{
		pos = (y * a->img.size_l + a->mlx.x * (a->img.bpp / 8));
		*(unsigned int *)(a->img.img + pos) = a->txr.c_rgb;
		y++;
	}
}

void	draw_walls(t_a *a)
{
	int		pos;

	while (a->img.px_start <= a->img.px_end)
	{
		pos = (a->img.px_start * a->img.size_l + a->mlx.x * (a->img.bpp / 8));
		a->tex.y = (int)a->tex.pos & (a->tex.dim - 1);
		*(unsigned int *)(a->img.img + pos) = a->tex.tx.img[a->tex.y
			* (a->tex.tx.size_l / 4) + a->tex.x];
		a->tex.pos += a->tex.step;
		a->img.px_start++;
	}
}

void	draw_floor(t_a *a)
{
	int		pos;

	while (a->img.px_start < a->res.h)
	{
		pos = (a->img.px_start * a->img.size_l + a->mlx.x * (a->img.bpp / 8));
		*(unsigned int *)(a->img.img + pos) = a->txr.f_rgb;
		a->img.px_start++;
	}
}

void	draw_spr_px(t_a *a, int stripe)
{
	int				y;
	int				pos;
	int				d;
	unsigned int	color;

	y = a->spr.px_start_y;
	while (y < a->spr.px_end_y)
	{
		pos = (y * a->img.size_l + stripe * (a->img.bpp / 8));
		d = y * 256 - a->res.h * 128 + a->spr.h * 128;
		a->tex.y = ((d * a->tex.dim) / a->spr.h) / 256;
		if (a->tex.y < 0)
			a->tex.y = 0;
		if (a->tex.x < 0)
			a->tex.x = 0;
		color = a->spr_txr.img[a->tex.y * (a->spr_txr.size_l / 4) + a->tex.x];
		if ((color & 0xFFFFFF) != 0)
			*(unsigned int *)(a->img.img + pos) = color;
		y++;
	}
}

void	draw_sprite(t_a *a)
{
	int				stripe;

	stripe = a->spr.px_start_x;
	while (stripe < a->spr.px_end_x)
	{
		a->tex.x = (int)(256 * (stripe - (-a->spr.w / 2 + a->spr.screen_x))
				* a->tex.dim / a->spr.w) / 256;
		if (a->spr.transf_y > 0 && stripe > 0 && stripe < a->res.w
			&& a->spr.transf_y < a->spr.z_buff[stripe])
			draw_spr_px(a, stripe);
		stripe++;
	}
}
