# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksappi <ksappi@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/05 15:32:21 by yyan              #+#    #+#              #
#    Updated: 2019/11/23 12:46:58 by ksappi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf*.c src/ft_atoi.c src/ft_bzero.c src/ft_intpow.c \
	src/ft_isdigit.c src/ft_itoa.c src/ft_memcpy.c \
	src/ft_strcat.c src/ft_strclen.c src/ft_strlen.c \
	src/ft_strnew.c src/ft_strcpy.c src/ft_lltoa.c \
	src/ft_strdup.c src/ft_memset.c

OBJ2 = $(SRC:.c=.o)

OBJ = $(subst src/,,$(OBJ2))

HEADER = ./src/includes/

FLAGS = -Wall -Wextra -Werror

LIBFT = ./src/libft.a

LIBFT = ./libft

all: $(NAME)

$(NAME):
	gcc -c $(FLAGS) $(SRC) -I$(HEADER) -I.
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, re, clean, fclean, $(NAME)
