# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eoddish <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/02 17:40:26 by eoddish           #+#    #+#              #
#    Updated: 2021/04/23 19:08:18 by eoddish          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_putnbr_fd.c ft_putchar_fd.c ft_itoa.c ft_split.c ft_strtrim.c ft_strjoin.c ft_calloc.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c  ft_strlcpy.c  ft_bzero.c ft_memcpy.c  ft_strlen.c


OBJS		= $(SRCS:.c=.o)


NAME		= libft.a

CC			= gcc

RM			= rm -f

AR			= ar

CFLAGS		= -Wall -Wextra -Werror

%.o: %.c
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
			$(AR) -rcs $@ $^

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all, clean, fclean, all

.SILENT:
