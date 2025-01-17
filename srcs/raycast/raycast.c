/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 14:24:39 by plam              #+#    #+#             */
/*   Updated: 2021/01/10 23:40:26 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	rc_loop(t_a *a)
{
	key_move(a);
	a->mlx.x = 0;
	while (a->mlx.x < a->res.w)
	{
		rc_dir(a);
		rc_dst(a);
		rc_hit(a);
		rc_line(a);
		rc_tex(a);
		draw_ceiling(a);
		draw_walls(a);
		draw_floor(a);
		a->mlx.x++;
	}
	sprite_raycast(a);
	if (a->bmp.fd > 0)
	{
		init_bmp(a);
		rec_bmp_h(a);
		rec_px(a);
		close(a->bmp.fd);
		destroy(a);
	}
	mlx_put_image_to_window(a->mlx.ptr, a->mlx.win, a->img.img_ptr, 0, 0);
	return (OK);
}

int	image_loader(t_a *a)
{
	wall_set(a);
	sprite_set(a);
	if (a->bmp.fd == 0)
		a->mlx.win = mlx_new_window(a->mlx.ptr, a->res.w, a->res.h, "cub3D");
	a->img.img_ptr = mlx_new_image(a->mlx.ptr, a->res.w, a->res.h);
	a->img.img = mlx_get_data_addr(a->img.img_ptr, &a->img.bpp, &a->img.size_l
			, &a->img.endian);
	return (OK);
}
