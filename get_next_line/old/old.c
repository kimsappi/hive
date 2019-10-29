#include "get_next_line.h"
#include <fcntl.h> //vitsiin
#include <stdio.h> //vitsiin

int		get_next_line(const int fd, char **line)
{
	static char	buff[BUFF_SIZE + 1];
	ssize_t		read_bytes;
	static char	*newline = NULL;
	char		has_been_copied;
	
	if (fd < 0 || !line || !(*line))
		return (-1);
	has_been_copied = 0;
	if (newline)
	{
		if (ft_strchr(newline + 1, '\n'))
		{
			if (*(newline + 1) != '\n')
				ft_strncpy(*line, newline + 1, (ft_strchr(newline + 1, '\n') - (newline)) / sizeof(char));
			else
				ft_strcpy(*line, "");
			newline = ft_strchr(newline + 1, '\n');
			return (1);
		}
		else
		{
			ft_strcpy(*line, newline + sizeof(char));
			newline = NULL;
		}
		has_been_copied = 1;
	}
	while ((read_bytes = read(fd, buff, BUFF_SIZE)))
	{
		if (read_bytes == -1)
			return (-1);
		if (read_bytes < BUFF_SIZE) // not sure if this will work with stdin
			return (0);
		if (*buff == '\n')
		{
			if (!has_been_copied)
				ft_strcpy(*line, "");
			newline = buff;
			return (1);
		}			
		buff[read_bytes] = 0;
		if ((newline = ft_strchr(buff, '\n')))
		{
			if (has_been_copied)
				ft_strncat(*line, buff, newline - buff);
			else
				ft_strncpy(*line, buff, newline - buff);
			break;
		}
		if (has_been_copied)
			ft_strcat(*line, buff);
		else
		{
			ft_strcpy(*line, buff);
			has_been_copied = 1;
		}
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