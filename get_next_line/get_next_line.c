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
			ft_strncat(*line, newline + 1, (ft_strchr(newline + 1, '\n') - (newline + 1)) / sizeof(char));
			return (*line);
		}
		else
			ft_strcat(*line, newline + 1);
	}
	while (read_bytes = read(fd, buff, BUFF_SIZE))
	{
		if (read_bytes == -1)
			return (-1);
		buff[read_bytes] = 0;
		if (newline = ft_strchr(buff, '\n'))
			break;
		ft_strcat(*line, buff);
	}

	return (*line);
}
