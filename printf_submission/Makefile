# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksappi <ksappi@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/05 15:32:21 by ksappi            #+#    #+#              #
#    Updated: 2019/11/26 13:48:18 by ksappi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_FILES = ft_atoi.c ft_bzero.c ft_intpow.c \
	ft_isdigit.c ft_itoa.c ft_memcpy.c \
	ft_strcat.c ft_strclen.c ft_strlen.c \
	ft_strnew.c ft_strcpy.c ft_lltoa.c \
	ft_strdup.c ft_memset.c ft_itoa_base.c \
	ft_strcat_and_free.c \
	ft_printf_float.c \
	ft_printf_get_style.c \
	ft_printf_int.c \
	ft_printf_padding.c \
	ft_printf_text.c \
	ft_printf_uint_base.c \
	ft_printf_utils.c \
	ft_printf.c \
	ft_strncpy.c

OBJ = $(subst .c,.o,$(SRC_FILES))

SRC_DIR = src/

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))

FLAGS = -Wall -Wextra -Werror

INCLUDES = includes

all: $(NAME)

$(OBJ):
	gcc -c $(FLAGS) $(SRC) -I$(INCLUDES)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(NAME): $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, re, clean, fclean, $(NAME)
