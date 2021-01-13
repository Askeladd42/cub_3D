/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 16:18:25 by plam              #+#    #+#             */
/*   Updated: 2021/01/05 13:47:46 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# define CUB ".cub"
# define SAVE "--save"

typedef struct s_res
{
	int		w;
	int		h;
}				t_res;

typedef struct s_txr
{
	char	*n;
	char	*s;
	char	*w;
	char	*e;
	char	*spr;
	char	*f;
	char	*c;
	int		f_rgb;
	int		c_rgb;
}				t_txr;

typedef struct s_map
{
	char	**map;
	char	**m_cp;
	int		y;
	int		x;
	int		hit;
	int		side;
	t_list	*first;
	t_list	*lst;
}				t_map;

typedef struct s_plr
{
	double	pos_x;
	double	pos_y;
	double	move_spd;
	double	rot_spd;
}				t_plr;

#endif
