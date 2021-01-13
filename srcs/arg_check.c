/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 13:19:18 by plam              #+#    #+#             */
/*   Updated: 2021/01/10 21:51:00 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cub_check(char *av, t_a *a)
{
	int	i;
	int	j;

	i = 0;
	j = 3;
	while (av[i])
		i++;
	i--;
	while (av[i--] == CUB[j] && j != -1)
		j--;
	if (j == -1)
	{
		a->mlx.fd = open(av, O_RDONLY);
		if (a->mlx.fd == -1)
			error(MISS_CUB_FILE, a);
	}
	else
		error(NOT_CUB_FILE, a);
}

void	save_check(char *av, t_a *a)
{
	int	i;

	i = 0;
	while (SAVE[i] && av[i])
	{
		if (SAVE[i] != av[i])
			error(SAVE_FAIL, a);
		i++;
	}
	if (SAVE[i] || av[i])
		error(SAVE_FAIL, a);
	a->bmp.fd = 1;
}
