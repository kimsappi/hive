# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksappi <ksappi@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/05 15:32:21 by yyan              #+#    #+#              #
#    Updated: 2019/11/23 13:31:01 by ksappi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = src/ft_atoi.c src/ft_bzero.c src/ft_intpow.c \
	src/ft_isdigit.c src/ft_itoa.c src/ft_memcpy.c \
	src/ft_strcat.c src/ft_strclen.c src/ft_strlen.c \
	src/ft_strnew.c src/ft_strcpy.c src/ft_lltoa.c \
	src/ft_strdup.c src/ft_memset.c src/ft_itoa_base.c \
	src/ft_strcat_and_free.c \
	src/ft_printf_float.c \
	src/ft_printf_get_style.c \
	src/ft_printf_int.c \
	src/ft_printf_padding.c \
	src/ft_printf_text.c \
	src/ft_printf_uint_base.c \
	src/ft_printf_utils.c \
	src/ft_printf.c

OBJ2 = $(subst .c,.o,$(SRC))

OBJ = $(subst src/,,$(OBJ2))

FLAGS = -Wall -Wextra -Werror

INCLUDES = includes

all: $(NAME)

$(NAME):
	gcc -c $(FLAGS) $(SRC) -I$(INCLUDES)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, re, clean, fclean, $(NAME)
