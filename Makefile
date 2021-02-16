# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esidelar <esidelar@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/15 11:25:27 by esidelar          #+#    #+#              #
#    Updated: 2021/02/16 11:20:43 by esidelar         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME	= 	philo
HEADERS	=	include/philosophers.h
CC		=	gcc
CFLAGS 	= 	-Wall -Wextra -Werror

################################################################################
#							   	   PHILOSOPHERS	  	   						   #
################################################################################

SRCS =		philosophers.c \
			ft_isnum.c \
			ft_atoi.c \
			ft_sleep.c \
			parsing.c \

OBJS	= 	$(SRCS:.c=.o)


all		: 	$(NAME)

$(NAME)	:	$(OBJS)
		gcc $(CFLAGS) $(OBJS) -o $(NAME) -lpthread

%.o: %.c $(HEADERS)
		clang $(FLAG) -c $< -o $@ -I $(HEADERS)

clean	:
		rm -f $(OBJS)
			
fclean	:	clean
		rm -f $(NAME)

re		: 	fclean all
