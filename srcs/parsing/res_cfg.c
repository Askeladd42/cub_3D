/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   res_cfg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 23:59:20 by plam              #+#    #+#             */
/*   Updated: 2021/01/11 10:53:21 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*size_check(char *line, int *res, int screen)
{
	*res = ft_atoi(line);
	if (*res > screen)
		*res = screen;
	while (*line >= '0' && *line <= '9')
		line++;
	return (line);
}

void	res_parse(t_a *a)
{
	int		w;
	int		h;
	char	*line;

	line = *a->mlx.line;
	if (dup_check(*line) == ERR)
		error(TOO_MANY_RES, a);
	line++;
	while (*line == ' ')
		line++;
	mlx_get_screen_size(a->mlx.ptr, &w, &h);
	line = size_check(line, &a->res.w, w);
	while (*line == ' ')
		line++;
	line = size_check(line, &a->res.h, h);
	if (*line != '\0')
		a->res.w = 0;
	if (a->res.w <= 0 || a->res.h <= 0)
		error(NOT_VALID_RES, a);
}
