/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 21:45:07 by plam              #+#    #+#             */
/*   Updated: 2021/01/13 00:35:02 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include <math.h>
# include "../libs/minilibx_linux/mlx.h"

# define ESC 65307
# define FW 119
# define BW 115
# define L 97
# define R 100
# define LR 65361
# define RR 65363
# define RUN 65505
# define FIRE 32
# define ACTION 101

# define MOTION_NOTIFY_CODE 06
# define STRUCTURE_NOTIFY_CODE 17

typedef struct s_mlx
{
	int		fd;
	void	*ptr;
	void	*win;
	int		x;
	char	**line;
}				t_mlx;

typedef struct s_dir
{
	double	x;
	double	y;
	double	old_x;
	double	plane_x;
	double	plane_y;
	double	oldplane_x;
	double	cam_x;
	double	cam_y;
	double	ray_x;
	double	ray_y;
}				t_dir;

typedef struct s_dst
{
	double	side_x;
	double	side_y;
	double	delta_x;
	double	delta_y;
	double	wall;
	int		step_x;
	int		step_y;
}				t_dst;

typedef struct s_img
{
	int		line_h;
	int		px_start;
	int		px_end;
	int		color;
	void	*img_ptr;
	int		bpp;
	int		size_l;
	int		endian;
	char	*img;
}				t_img;

typedef struct s_mov
{
	char	mov[70000];
}				t_mov;

typedef struct s_atx
{
	void	*ptr;
	int		bpp;
	int		size_l;
	int		endian;
	int		*img;
}				t_atx;

typedef struct s_tex
{
	int		dim;
	t_atx	tx;
	double	wall_x;
	int		x;
	int		y;
	double	step;
	double	pos;
}				t_tex;

typedef struct s_spr
{
	double	*pos_x;
	double	*pos_y;
	double	*z_buff;
	int		*order;
	double	*dist;
	int		amount;
	double	spr_x;
	double	spr_y;
	double	inv_det;
	double	transf_x;
	double	transf_y;
	int		screen_x;
	int		h;
	int		w;
	int		px_start_y;
	int		px_end_y;
	int		px_start_x;
	int		px_end_x;
}				t_spr;

typedef struct s_bmp
{
	int		fd;
	int		sign;
	int		size;
	int		rsv;
	int		offset;
	int		dib_size_h;
	int		dib_height;
	int		dib_width;
	int		dib_clr_pln;
	int		dib_bpp;
}				t_bmp;

#endif
