/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 12:01:14 by plam              #+#    #+#             */
/*   Updated: 2021/01/10 21:47:53 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_atx	wall_select(t_a *a)
{
	if (a->map.side == 1 && a->dst.step_y == 1)
		return (a->ntx);
	else if (a->map.side == 1 && a->dst.step_y == -1)
		return (a->stx);
	else if (a->map.side == 0 && a->dst.step_x == -1)
		return (a->etx);
	return (a->wtx);
}
