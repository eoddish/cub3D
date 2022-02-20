# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eoddish <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/02 17:40:26 by eoddish           #+#    #+#              #
#    Updated: 2021/04/22 21:10:59 by eoddish          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3D

SRCS		= ft_parser.c ft_cube.c ft_parse_c.c\
			  ft_parse_ea.c ft_parse_no.c ft_parse_s.c\
			  ft_parse_r.c ft_parse_so.c ft_parse_we.c\
			  get_next_line.c get_next_line_utils.c\
			  ft_parse_f.c  ft_error.c ft_parse_spr.c\
			  ft_mapcheck.c ft_mlx.c ft_ray_cast.c\
			  ft_player.c ft_maze.c ft_keypress.c\
			  ft_image.c ft_draw_spr.c ft_sort_spr.c\
			  ft_color.c ft_save.c ft_move_plr.c\
			ft_draw_wall.c

OBJS		= $(SRCS:.c=.o)

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

%.o: %.c	
			$(CC) $(CFLAGS) -Imlx -c $< -o $@

RM			= rm -f

LIBFT		= libft

MLX			= mlx

MLX_NAME	= libmlx.dylib

LIBFT_NAME	= libft.a

MAKE		= make -C

$(NAME):	$(OBJS)
			$(MAKE) $(LIBFT)
			$(MAKE) $(MLX)
			cp $(MLX)/$(MLX_NAME) ./$(MLX_NAME)
			$(CC) $(CFLAGS) $(OBJS) libft/libft.a\
			   	-Lmlx -lmlx -framework OpenGL -framework\
			   	AppKit -o $(NAME)

all:		$(NAME)

clean:
			$(RM) $(OBJS) $(LIBFT)/$(LIBFT_NAME) $(LIBFT)/*.o\
			$(MLX)/$(MLX_NAME) $(MLX_NAME) $(MLX)/*.o

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all, clean, fclean, re

.SILENT:
