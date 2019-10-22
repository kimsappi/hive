#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft.h"
# define BUFF_SIZE 10

typedef struct	s_filebuff {
	char	*buff;
	int		fd;
}				t_filebuff;

int	get_next_line(const int fd, char **line);

#endif
