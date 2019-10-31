/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksappi <ksappi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 11:38:27 by ksappi            #+#    #+#             */
/*   Updated: 2019/10/29 14:30:59 by ksappi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h> //remove

/*
static t_filebuff	*ft_gnl_get_file(t_list **file_list, const int fd)
{
	t_list		*new_element;
	t_filebuff	new_file;

	if (*file_list)
	{
		new_element = *file_list;
		while (new_element)
		{
			if (((t_filebuff*)(new_element->content))->fd == fd)
				return ((t_filebuff*)(new_element->content));
			new_element = new_element->next;
		}
	}
	if (!(new_file.buff = ft_strnew(0)))
		return (NULL);
	new_file.fd = fd;
	if (!(new_element = ft_lstnew(&new_file, sizeof(t_filebuff))))
	{
		free(new_file.buff);
		return (NULL);
	}
	ft_lstadd(file_list, new_element);
	return ((t_filebuff*)new_element->content);
}
*/
static ssize_t		ft_gnl_read_line(char **file_buff, const int fd)
{
	char	buff[BUFF_SIZE + 1];
	ssize_t	read_bytes;
	char	*temp;

	read_bytes = 1;
	while (read_bytes && !ft_strchr((const char *)(*file_buff), '\n'))
	{
		read_bytes = read(fd, buff, BUFF_SIZE);
		if (read_bytes == -1)
			return (-1);

			//printf("%s", buff);

		buff[read_bytes] = 0;
		temp = *file_buff;
		*file_buff = ft_strjoin(*file_buff, buff);
		free(temp);
		if (!(*file_buff))
			return (-1);
	}
//	printf("\nfilebuff after reading:\n%s\n", file_buff);
	return (read_bytes);
}
/*
static void			ft_gnl_free_file(t_filebuff **file, t_list **file_list)
{
	t_list	*temp;

	if (file_list && file && *file_list && *file)
	{
		temp = *file_list;
		while ((*file_list)->next && (*file_list)->next->content != *file)
			*file_list = (*file_list)->next;
		temp = (*file_list)->next;
		if (temp)
			(*file_list)->next = temp->next;
		if (temp)
		{
			if (((t_filebuff*)(temp->content))->buff)
				free(((t_filebuff*)(temp->content))->buff);
			if (temp->content)
				free(temp->content);
			if (temp)
				free(temp);
			temp = NULL;
		}
	}
}
*/

int					get_next_line(const int fd, char **line)
{
	static char	*buffs[MAX_FD];
	int			ret;
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
	//printf("%s\n", buffs[fd]);
	line_length = ft_strclen(buffs[fd], '\n');
	//printf("%d\n", line_length);
	*line = ft_strnew(line_length);
	ft_memccpy(*line, buffs[fd], '\n', line_length);
	if (line_length && (*line)[line_length - 1] == '\n')
		(*line)[line_length - 1] = 0;
	//printf("%s\n", *line);
	temp = buffs[fd];
	buffs[fd] = ft_strdup(&(buffs[fd][line_length + 1]));
	free(temp);
	if (!(buffs[fd]))
		return (-1);
	if (ret > 0)
		return (1);
	if (ret < 1)
	{
		free(buffs[fd]);
		buffs[fd] = NULL;
	}
	return (ret);
}
