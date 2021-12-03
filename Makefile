# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esidelar <esidelar@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/15 11:25:27 by esidelar          #+#    #+#              #
#    Updated: 2021/12/01 17:27:23 by esidelar         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME	= 	philo
HEADERS	=	include/philosophers.h
CC		=	gcc
CFLAGS 	= 	-Wall -Wextra -Werror

################################################################################
#							   	   PHILOSOPHERS	  	   						   #
################################################################################

SRCS =		main.c \
			philosophers.c \
			ft_isnum.c \
			ft_atoi.c \
			set_time.c \
			parsing.c \
			check.c \

OBJS	= 	$(SRCS:.c=.o)


all		: 	$(NAME)

$(NAME)	:	$(OBJS)
		gcc $(CFLAGS) $(OBJS) -o $(NAME) -lpthread

%.o: %.c $(HEADERS)
		gcc $(CFLAGS) -c $< -o $@ -I $(HEADERS)

clean	:
		rm -f $(OBJS)
			
fclean	:	clean
		rm -f $(NAME)

re		: 	fclean all
