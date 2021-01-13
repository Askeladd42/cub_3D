/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   txr_cfg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 17:02:47 by plam              #+#    #+#             */
/*   Updated: 2021/01/12 23:57:11 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_wall(t_a *a)
{
	a->ntx.ptr = 0;
	a->stx.ptr = 0;
	a->etx.ptr = 0;
	a->wtx.ptr = 0;
}

void	txr_cpy(char c, char *line, int len, t_txr *txr)
{
	if (c == 'N')
		ft_strlcpy(txr->n, line, len + 1);
	else if (c == 'S')
		ft_strlcpy(txr->s, line, len + 1);
	else if (c == 'W')
		ft_strlcpy(txr->w, line, len + 1);
	else if (c == 'E')
		ft_strlcpy(txr->e, line, len + 1);
	else if (c == ' ')
		ft_strlcpy(txr->spr, line, len + 1);
	else if (c == 'F')
		ft_strlcpy(txr->f, line, len + 1);
	else if (c == 'C')
		ft_strlcpy(txr->c, line, len + 1);
}

int	dup_check(char c)
{
	int			i;
	static char	tab[10];

	i = 0;
	while (tab[i] != '\0')
	{
		if (tab[i] == c)
			return (ERR);
		i++;
	}
	tab[i] = c;
	return (i);
}

void	txr_path(char c, char *line, t_a *a)
{
	int	len;

	len = 0;
	if (c == 'F' || c == 'C')
	{
		if (!(*line >= '0' && *line <= '9'))
			error(NOT_VALID_COLOR, a);
		if (txr_atoi(c, line, &a->txr) == ERR)
			error(NOT_VALID_COLOR, a);
	}
	else
	{
		while (*(line + len) != '\0' && *(line + len) != ' ')
			len++;
		txr_malloc(c, len, a);
		txr_cpy(c, line, len, &a->txr);
	}
}

void	txr_parse(char c, char *line, t_a *a)
{
	line++;
	if ((c == 'N' && *line != 'O') || (c == 'W' && *line != 'E')
		|| (c == 'S' && (*line != ' ' && *line != 'O'))
		|| (c == 'E' && *line != 'A')
		|| ((c == 'F' || c == 'C') && *line != ' '))
		error(NOT_VALID_TXR, a);
	if (c == 'S' && *line == 'O')
		c = 'S';
	else if (c == 'S' && *line == ' ')
		c = ' ';
	if (dup_check(c) == ERR)
		error(TOO_MANY_TXR, a);
	line++;
	while (*line == ' ')
		line++;
	txr_path(c, line, a);
}
