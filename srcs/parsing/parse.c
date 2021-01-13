/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 16:31:18 by plam              #+#    #+#             */
/*   Updated: 2021/01/13 00:29:49 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_vfy(t_a *a)
{
	if (dup_check('c') != 8)
	{
		free_line(a);
		error(NOT_ENOUGH_ID, a);
	}
	map_parse(a);
	sprite_list(a);
}

void	parse(t_a *a)
{
	char	*line;
	int		i;

	while (get_next_line(a->mlx.fd, a->mlx.line) > 0)
	{
		i = 0;
		line = *a->mlx.line;
		while (line[i] == ' ')
			i++;
		if (line[i] == 'R')
			res_parse(a);
		else if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W'
			|| line[i] == 'E' || line[i] == 'F' || line[i] == 'C')
			txr_parse(line[i], line + i, a);
		else if (line[i] == '0' || line[i] == '1'
			|| line[i] == '2' || line[i] == ' ')
			return (map_vfy(a));
		else if (line[i] != ' ' && line[i])
			error(NOT_VALID_ID, a);
		free_line(a);
	}
	free_line(a);
	error(NOT_ENOUGH_ID, a);
}
