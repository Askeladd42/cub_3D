# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plam <plam@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/08 18:12:57 by plam              #+#    #+#              #
#    Updated: 2021/01/07 09:16:19 by plam             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= \
		ft_atoi.c		ft_isalnum.c		ft_putchar_fd.c	\
		ft_itoa.c		ft_isalpha.c		ft_putstr_fd.c	\
		ft_bzero.c		ft_isascii.c		ft_putendl_fd.c	\
		ft_split.c		ft_isdigit.c		ft_putnbr_fd.c	\
		ft_memset.c		ft_isprint.c		ft_strtrim.c	\
		ft_calloc.c		ft_memccpy.c		ft_substr.c		\
		ft_memchr.c		ft_strjoin.c	\
		ft_memcmp.c		ft_strlcat.c	\
		ft_memcpy.c		ft_strlcpy.c	\
		ft_strchr.c		ft_strncmp.c	\
		ft_strdup.c		ft_strnstr.c	\
		ft_strlen.c		ft_strrchr.c	\
		ft_memmove.c	ft_tolower.c	\
		ft_toupper.c	ft_strmapi.c	\

SRCS2	= \
		ft_lstadd_front_bonus.c		ft_lstclear_bonus.c		ft_lstiter_bonus.c\
		ft_lstadd_back_bonus.c		ft_lstsize_bonus.c		ft_lstmap_bonus.c\
		ft_lstdelone_bonus.c		ft_lstlast_bonus.c		ft_lstnew_bonus.c\

OBJS		= ${SRCS:.c=.o}

OBJS_BONUS	= ${SRCS2:.c=.o}

NAME		= libft.a

CC			= /usr/bin/clang

RM			= /bin/rm -f

CFLAGS		+=	-Wall -Wextra -Werror --include libft.h

.PHONY: bonus fclean clean re

all:		$(NAME)

$(NAME):	${OBJS} ${OBJS_BONUS}
			/usr/bin/ar rcs $(NAME) ${OBJS} ${OBJS_BONUS}

bonus:		${OBJS_BONUS}
			/usr/bin/ar rcs $(NAME) ${OBJS_BONUS}

clean :
			${RM} ${OBJS} ${OBJS_BONUS}

fclean :	clean
			${RM} $(NAME)

re :		fclean all
