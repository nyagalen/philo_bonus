# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svydrina <svydrina@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/30 05:46:49 by svydrina          #+#    #+#              #
#    Updated: 2023/12/30 05:52:31 by svydrina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

CC = cc -Wall -Werror -Wextra

SRCS = main.c init.c utils.c utils2.c

OBJS = $(SRCS:.c=.o)

.c.o:
	$(CC) -c $< -o $@
