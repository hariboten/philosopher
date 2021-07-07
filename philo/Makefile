# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ewatanab <ewatanab@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/07 14:55:05 by ewatanab          #+#    #+#              #
#    Updated: 2021/07/07 15:33:07 by ewatanab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SRCDIR = ./src/
SRCNAMES = \
	main.c \
	dpp.c \
	philo.c \
	philo_utils.c \
	observer.c \
	action.c \
	utils.c
SRCS = $(addprefix $(SRCDIR), $(SRCNAMES))
OBJDIR = ./obj/
OBJS = $(SRCNAMES:%.c=$(OBJDIR)%.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g -O0

all : $(OBJDIR) $(NAME)

$(OBJDIR) :
	mkdir -p $@

$(OBJDIR)%.o : $(SRCDIR)%.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ -pthread

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.phony: all fclean clean re
