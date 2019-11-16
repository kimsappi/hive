# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksappi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/05 15:32:21 by yyan              #+#    #+#              #
#    Updated: 2019/11/16 12:54:23 by ksappi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c

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
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
	make clean -C ./libft

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft

re: fclean all

.PHONY: all, re, clean, fclean, obj, $(NAME)
