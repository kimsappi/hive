NAME = fillit

SRC = main.c solver.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

LIBFT = ./libft/libft.a

$(NAME): libft

	
libft:
	make -C ./libft

clean:
	rm -f $(OBJ)
	make clean -C ./libft

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft

re: fclean all

.PHONY: all, re, clean, fclean, $(NAME)
