/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clr_cfg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 17:02:44 by plam              #+#    #+#             */
/*   Updated: 2021/01/10 22:53:17 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	txr_atoi(char c, char *line, t_txr *txr)
{
	int	i;
	int	rgb[3];

	i = -1;
	while (++i <= 2)
	{
		while (*line == ' ')
			line++;
		rgb[i] = ft_atoi(line);
		if (rgb[i] < 0 || rgb[i] > 255)
			return (ERR);
		if (!(*line >= '0' && *line <= '9'))
			return (ERR);
		while (*line >= '0' && *line <= '9')
			line++;
		if (i == 2 && *line != '\0')
			return (ERR);
		if (i != 2 && *line++ != ',')
			return (ERR);
	}
	if (c == 'F')
		txr->f_rgb = 65536 * rgb[0] + 256 * rgb[1] + rgb[2];
	else if (c == 'C')
		txr->c_rgb = 65536 * rgb[0] + 256 * rgb[1] + rgb[2];
	return (OK);
}
