# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ewatanab <ewatanab@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/07 14:55:05 by ewatanab          #+#    #+#              #
#    Updated: 2021/07/08 16:58:24 by ewatanab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SRCDIR = ./src/
SRCNAMES = \
		main.c \
		philo.c \
		philo_utils.c \
		dpp.c \
		observer.c \
		action.c \
		utils.c
SRCS = $(addprefix $(SRCDIR), $(SRCNAMES))
OBJDIR = ./obj/
OBJS = $(SRCNAMES:%.c=$(OBJDIR)%.o)

#LIBFTDIR = ./libft/
#LIBFT = libft.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra # -g -O0

all : $(OBJDIR) $(NAME)

$(NAME) : $(OBJS) # (LIBFT)
	$(CC) $(CFLAGS) -o $@ $^ -pthread # -L $(LIBFTDIR) -lft

$(OBJDIR) :
	mkdir -p $@

$(OBJDIR)%.o : $(SRCDIR)%.c
	$(CC) $(CFLAGS) -c -o $@ $<

#(LIBFT)
#	make -C $(LIBFTDIR)

clean :
	rm -f $(OBJS)
#	make clean -C $(LIBFTDIR)

fclean : clean
	rm -f $(NAME)
#	make fclean -C $(LIBFTDIR)

re : fclean all

.phony: all fclean clean re
