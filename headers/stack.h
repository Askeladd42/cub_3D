/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 23:45:54 by plam              #+#    #+#             */
/*   Updated: 2021/01/10 22:28:31 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# define TRUE 1
# define FALSE 0

typedef struct s_vec
{
	int			x;
	int			y;
}				t_vec;

typedef struct s_frame
{
	struct s_frame	*next;
	t_vec			pos;
}					t_frame;

typedef struct s_proj
{
	t_vec	pr;
	t_vec	n;
}				t_proj;

#endif
