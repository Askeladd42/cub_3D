/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 16:32:12 by plam              #+#    #+#             */
/*   Updated: 2021/01/12 12:56:53 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		disp_infos(t_a a)// a supprimer avant de push
{
	printf("\nRES :\nwidth = %d\nheight = %d\n", a.res.w, a.res.h);
	printf("\nTXR :\nnorth = %s\nsouth = %s\nwest = %s\neast = %s\nsprite = %s\n", a.txr.n, a.txr.s, a.txr.w, a.txr.e, a.txr.spr);
	printf("\nCLR :\nfloor :\nr = %d, g = %d, b = %d\nfloor = %s\nceilng :\nr = %d, g = %d, b = %d\nceiling = %s\n", a.txr.f_rgb / 256 / 256 % 256, a.txr.f_rgb / 256 % 256, a.txr.f_rgb % 256, a.txr.f, a.txr.c_rgb / 256 / 256 % 256, a.txr.c_rgb / 256 % 256, a.txr.c_rgb % 256, a.txr.c);
	printf("\nMAP :\n|         10        20        30        40        50|");
	printf("\n|012345678901234567890123456789012345678901234567890|\n");
	for (int i = 0; a.map.map[i] != NULL; i++)
		printf("|%s| %d\n", a.map.map[i], i);
}

int	main(int ac, char **av)
{
	t_a		a;

	init(&a);
	if (ac < 2)
		error(NOT_ENOUGH_ARGS, &a);
	else if (ac > 3)
		error(TOO_MANY_ARGS, &a);
	cub_check(av[1], &a);
	parse(&a);
	if (ac == 3)
		save_check(av[2], &a);
	image_loader(&a);
	if (a.bmp.fd == 0)
		play_music(&a);
	else
		rc_loop(&a);
	//disp_infos(a); // a supprimer avant de push et rendre
	mlx_hook(a.mlx.win, 2, (1L << 0), key_press, &a);
	mlx_hook(a.mlx.win, 3, (1L << 1), key_release, &a);
	mlx_hook(a.mlx.win, 33, (1L << 5), destroy, &a);
	mlx_loop_hook(a.mlx.ptr, rc_loop, &a);
	mlx_loop(a.mlx.ptr);
	return (OK);
}
