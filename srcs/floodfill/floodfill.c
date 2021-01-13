/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 17:14:29 by plam              #+#    #+#             */
/*   Updated: 2021/01/13 00:17:04 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** ici , Nord = (0, -1), Sud = (0, 1);
** Est = (1, 0) et Ouest = (-1, 0);
*/

int	find(char **map, t_frame **stack, t_vec proj)
{
	if (ft_strchr("023 ", map[proj.y][proj.x]))
	{
		if (stack_push(stack, proj) == ERR)
			return (ERR);
	}
	return (OK);
}

int	free_stack(t_frame *stack, t_proj p)
{
	while (stack_len(stack) != 0)
		p.n = stack_pop(&stack);
	return (FALSE);
}

int	flood_fill(char **map, t_vec pos, t_vec max, t_frame *stack)
{
	t_proj		p;
	int			i;

	stack = NULL;
	stack_push(&stack, pos);
	while (stack_len(stack) != 0)
	{
		p.n = stack_pop(&stack);
		map[p.n.y][p.n.x] = 'x';
		i = 0;
		while (i < 4)
		{
			p.pr = (t_vec){p.n.x + (int [4]){-1, 0, 1, 0}[i]
				, p.n.y + (int [4]){0, 1, 0, -1}[i]};
			if (p.pr.x >= 0 && p.pr.x < max.x && p.pr.y >= 0 && p.pr.y < max.y)
			{
				if (find(map, &stack, p.pr) == ERR)
					return (free_stack(stack, p));
			}
			else
				return (free_stack(stack, p));
			i++;
		}
	}
	return (TRUE);
}
