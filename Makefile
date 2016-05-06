#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kevgusma <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/21 15:36:40 by kevgusma          #+#    #+#              #
#    Updated: 2016/04/09 16:56:56 by kevgusma         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit

FLAG = -Wall -Werror -Wextra

SRC = fillit.c parsing.c backtracking.c

LIB = libft

LIBA = $(LIB)/libft.a

OBJ = $(subst .c,.o,$(SRC))

CC = clang

.PHONY: all libft clean fclean re

all: $(LIBA) $(NAME)

$(NAME): $(OBJ)
		$(CC)  -o $@ $^ $(FLAG) libft/libft.a

%.o:%.c
		$(CC) -o $@ -c $< -I $(LIBA) $(FLAG)

libft: $(LIBA)

$(LIBA):
		@make -C $(LIB)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME) $(MALLIB)

re: fclean all
