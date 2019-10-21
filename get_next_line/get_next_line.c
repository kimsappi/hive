#include "get_next_line.h"
#include <fcntl.h> //vitsiin
#include <stdio.h> //vitsiin

int		get_next_line(const int fd, char **line)
{
	static char	buff[BUFF_SIZE + 1];
	ssize_t		read_bytes;
	static char	*newline = NULL;
	
	if (fd < 0 || !line || !(*line))
		return (-1);
	if (newline)
	{
		if (ft_strchr(newline + 1, '\n'))
		{
			ft_strncat(*line, newline + 1, (ft_strchr(newline + 1, '\n') - (newline)) / sizeof(char));
			newline = ft_strchr(newline + 1, '\n');
			return (1);
		}
		else
		{
			ft_strcat(*line, newline + sizeof(char));
			newline = NULL;
		}
	}
	while ((read_bytes = read(fd, buff, BUFF_SIZE)))
	{
		if (read_bytes == -1)
			return (-1);
		if (read_bytes < BUFF_SIZE) // not sure if this will work with stdin
			return (0);
		buff[read_bytes] = 0;
		if ((newline = ft_strchr(buff, '\n')))
		{
			ft_strncat(*line, buff, newline - buff);
			break;
		}
		ft_strcat(*line, buff);
	}
	return (1);
}

int main(void) // vitsiin
{
	char *line = malloc(1024);
	int file = open("get_next_line.h", O_RDONLY);
	int i = 1;
	while (i > 0)
	{
		i = get_next_line(file, &line);
		printf("%d: %s\n", i, line);
		ft_strclr(line);
	}
	return (0);
}