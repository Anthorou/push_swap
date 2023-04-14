# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 13:50:51 by aroussea          #+#    #+#              #
#    Updated: 2023/03/30 16:54:57 by aroussea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
SOURCE = src/main.c \
		 src/push_swap.c \
		 src/push_swap_utils.c \
		 src/push_swap_utils2.c \
		 src/push_swap_utils3.c \
		 src/push_swap_utils4.c \
		 src/parsing.c \
		 src/free.c \
		 src/operation.c \
		 src/operation2.c \

HEADERS	:= -I ./include
LIBS	:= libft/libft.a
OBJS = $(SOURCE:.c=.o)

all: lib $(NAME)

lib:
	@make -C libft/

%.o : %.c 
	$(CC) -g $(CFLAGS) -o $@ -c $< $(HEADERS)
	
$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -f $(OBJS)
	@make -C libft/ clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft/ fclean
	$(info Tous propre!)

re: fclean all

.PHONY: all, clean, fclean, re