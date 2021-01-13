# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plam <plam@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/01 23:54:52 by plam              #+#    #+#              #
#    Updated: 2021/01/13 10:32:00 by plam             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GNL			=	gnl/get_next_line.c\
				gnl/get_next_line_utils.c

PRSG		= 	parsing/parse.c\
				parsing/res_cfg.c\
				parsing/txr_cfg.c\
				parsing/txr_malloc.c\
				parsing/clr_cfg.c\
				parsing/map_cfg.c\
				parsing/map_start.c\
				parsing/free_parse.c\
				parsing/free_struct.c

RC			=	raycast/raycast.c\
				raycast/raycast_walls.c\
				raycast/raycast_spr.c\

SPR			=	sprite/walls.c\
				sprite/tx_set.c\
				sprite/spr_cfg.c\
				sprite/spr_sort.c

KEY			=	keybinding/key_mv.c\
				keybinding/key_put.c

FDFL		=	floodfill/stack.c\
				floodfill/floodfill.c\
				floodfill/map_cpy.c

SRCS		=	$(GNL)\
				$(PRSG)\
				$(RC)\
				$(SPR)\
				$(KEY)\
				$(FDFL)\
				cub3d.c\
				init.c\
				display.c\
				bmp.c\
				music.c\
				error_cfg.c\
				arg_check.c


LIBS		= 	libs/libft/libft.a\
				libs/minilibx_linux/libmlx.a

PATH		= 	srcs/

OBJS		= 	$(addprefix $(PATH), $(SRCS))

NAME		= 	cub3D

CC			= 	/usr/bin/clang

HEADER		= 	headers/.

FLAGS		= 	-g -Wall -Wextra -Werror -I $(HEADER) -L/usr/include/../lib -lXext -lX11 -lm -lbsd

RM			= 	/bin/rm -f

LIBFT		= 	libs/libft

LIBX		=	libs/minilibx_linux

BMP			= 	save.bmp

MAKE		= 	/usr/bin/make -s

all:		$(NAME)

$(NAME):	$(OBJS)
			@cd $(LIBFT) && $(MAKE) && $(MAKE) bonus && $(MAKE) clean
			$(CC) $(FLAGS) $(OBJS) $(LIBS) -o $(NAME)
	
clean:
			$(RM) $(LIBFT)/libft.a

fclean:		clean
			$(RM) $(NAME) $(BMP)

re:			fclean all

.PHONY:		all clean fclean re bonus