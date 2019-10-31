/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksappi <ksappi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 11:38:27 by ksappi            #+#    #+#             */
/*   Updated: 2019/10/31 11:03:06 by ksappi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	gnl_get_return_value(char ret, char **file_buff)
{
	if (!(*file_buff))
		return (-1);
	if (ret > 0)
		return (1);
	if (ret < 1)
	{
		free(*file_buff);
		*file_buff = NULL;
	}
	return (ret);
}

static char	ft_gnl_read_line(char **file_buff, const int fd)
{
	char	buff[BUFF_SIZE + 1];
	ssize_t	read_bytes;
	char	*temp;
	char	ret;

	ret = 0;
	read_bytes = 1;
	while (read_bytes && !ft_strchr((const char *)(*file_buff), '\n'))
	{
		read_bytes = read(fd, buff, BUFF_SIZE);
		if (read_bytes == -1)
			return (-1);
		if (read_bytes > 0 || **file_buff)
			ret = 1;
		buff[read_bytes] = 0;
		temp = *file_buff;
		*file_buff = ft_strjoin(*file_buff, buff);
		free(temp);
		if (!(*file_buff))
			return (-1);
	}
	if (read_bytes > 0)
		ret = 1;
	return (ret);
}

int			get_next_line(const int fd, char **line)
{
	static char	*buffs[MAX_FD];
	char		ret;
	char		*temp;
	int			line_length;

	if (fd < 0 || fd > MAX_FD || BUFF_SIZE < 1 || BUFF_SIZE > MAX_BUFF || !line)
		return (-1);
	if (!(buffs[fd]))
	{
		if (!(buffs[fd] = ft_strnew(0)))
			return (-1);
	}
	if ((ret = ft_gnl_read_line(&(buffs[fd]), fd)) == -1)
		return (-1);
	line_length = ft_strclen(buffs[fd], '\n');
	*line = ft_strnew(line_length);
	ft_memccpy(*line, buffs[fd], '\n', line_length);
	if (line_length && (*line)[line_length - 1] == '\n')
		(*line)[line_length - 1] = 0;
	temp = buffs[fd];
	buffs[fd] = ft_strdup(&(buffs[fd][line_length + 1]));
	free(temp);
	return (gnl_get_return_value(ret, &(buffs[fd])));
}
