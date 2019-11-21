# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksappi <ksappi@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/05 15:32:21 by yyan              #+#    #+#              #
#    Updated: 2019/11/16 14:09:30 by ksappi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = libft/ft_printf.c libft/ft_atoi.c libft/ft_bzero.c libft/ft_intpow.c \
	libft/ft_isdigit.c libft/ft_itoa.c libft/ft_memcpy.c \
	libft/ft_strcat.c libft/ft_strclen.c libft/ft_strlen.c \
	libft/ft_strnew.c libft/ft_strcpy.c

OBJ2 = $(SRC:.c=.o)

OBJ = $(subst libft/,,$(OBJ2))

HEADER = ./libft/includes/

FLAGS = -Wall -Wextra -Werror

LIBFT = ./libft/libft.a

LIBFT = ./libft

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(SRC) -I$(HEADER) -I.
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, re, clean, fclean, $(NAME)
