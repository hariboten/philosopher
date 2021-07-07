# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ewatanab <ewatanab@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/07 14:55:05 by ewatanab          #+#    #+#              #
#    Updated: 2021/07/07 15:04:10 by ewatanab         ###   ########.fr        #
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
CFLAGS = -Wall -Werror -Wextra

all : $(objdir) $(name)

$(objdir) :
	mkdir -p obj

$(objdir)%.o : $(srcdir)%.c
	$(cc) $(cflags) -c -o $@ $<

$(name) : $(objs)
	make -c $(libdir)
	$(cc) $(cflags) -o $@ $^ -pthreads

clean :
	rm -f $(objs)

fclean : clean
	rm -f $(name)

re : fclean all

.phony: all fclean clean re
