# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esidelar <esidelar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/15 11:25:27 by esidelar          #+#    #+#              #
#    Updated: 2021/12/05 14:56:31 by esidelar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	philo
HEADERS	=	./include/philosophers.h
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
			eat_sleep_think.c \

OBJS	= 	$(SRCS:.c=.o)


all		: 	$(NAME) $(HEADERS)

$(NAME)	:	$(OBJS)
		gcc $(CFLAGS) $(OBJS) -o $(NAME) -lpthread

%.o: %.c $(HEADERS)
		gcc $(CFLAGS) -c $< -o $@ -I $(HEADERS)

clean	:
		rm -f $(OBJS)
			
fclean	:	clean
		rm -f $(NAME)

re		: 	fclean all
