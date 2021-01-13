/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 23:43:05 by plam              #+#    #+#             */
/*   Updated: 2021/01/12 23:17:39 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_frame	*stack_init(t_vec pos)
{
	t_frame	*frame;

	frame = malloc(sizeof(t_frame));
	if (frame == NULL)
		return (NULL);
	frame->next = NULL;
	frame->pos = pos;
	return (frame);
}

int	stack_push(t_frame **item, t_vec pos)
{
	t_frame	*old;

	old = *item;
	*item = stack_init(pos);
	if (*item == NULL)
		return (ERR);
	(*item)->next = old;
	return (OK);
}

t_vec	stack_pop(t_frame **item)
{
	t_vec	pos;
	t_frame	*old;

	if (*item == NULL)
		return ((t_vec){INT_MAX, INT_MIN});
	old = *item;
	*item = (*item)->next;
	pos = old->pos;
	free(old);
	return (pos);
}

int	stack_len(t_frame *item)
{
	int	i;

	i = 0;
	while (item != NULL)
	{
		item = item->next;
		i++;
	}
	return (i);
}
