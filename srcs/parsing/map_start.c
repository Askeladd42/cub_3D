/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 23:01:42 by plam              #+#    #+#             */
/*   Updated: 2021/01/10 23:09:57 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	add_line(char *line, t_list **first, t_list **lst)
{
	*lst = ft_lstnew(line);
	if (*lst == NULL)
		return (ERR);
	ft_lstadd_back(first, *lst);
	return (OK);
}

void	start_dir(t_dir *dir, char *line, int x)
{
	if (line[x] == 'N')
	{
		dir->y = -1;
		dir->plane_x = 1;
	}	
	else if (line[x] == 'S')
	{
		dir->y = 1;
		dir->plane_x = -1;
	}
	else if (line[x] == 'W')
	{
		dir->x = -1;
		dir->plane_y = -1;
	}
	else if (line[x] == 'E')
	{
		dir->x = 1;
		dir->plane_y = 1;
	}
}

int	start_p(int y, char *line, t_plr *plr, t_dir *dir)
{
	int		x;

	x = 0;
	while (line[x] != '\0')
	{
		if (line[x] == 'N' || line[x] == 'S'
			|| line[x] == 'W' || line[x] == 'E')
		{
			if (plr->pos_y != -1)
				return (ERR);
			plr->pos_x = x + 0.5;
			plr->pos_y = y + 0.5;
		}
		start_dir(dir, line, x);
		x++;
	}
	return (OK);
}
