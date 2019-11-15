# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yyan <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/05 15:32:21 by yyan              #+#    #+#              #
#    Updated: 2019/11/05 16:23:27 by yyan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = main.c solve.c get_input.c

OBJ = $(SRC:.c=.o)

HEADER = ./libft/includes/

FLAGS = -Wall -Wextra -Werror

LIBFT = ./libft/libft.a

LIBFT = ./libft

all: $(NAME)

obj:
	gcc $(FLAGS) -c $(SRC) -I$(HEADER) -I.

$(NAME): obj
	make -C $(LIBFT)
	gcc $(FLAGS) -o $(NAME) $(OBJ) -L libft -lft

clean:
	rm -f $(OBJ)
	make clean -C ./libft

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft

re: fclean all

.PHONY: all, re, clean, fclean, obj, $(NAME)
