/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksappi <ksappi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 11:38:27 by ksappi            #+#    #+#             */
/*   Updated: 2019/10/24 16:49:15 by ksappi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h> //vitsiin

static t_filebuff		*ft_gnl_get_file(t_list **file_list, const int fd)
{
	t_list		*new_element;
	t_filebuff	new_file;

	new_element = *file_list;
	while (new_element)
	{
		if (((t_filebuff*)(new_element->content))->fd == fd)
			return ((t_filebuff*)(new_element->content));
		new_element = new_element->next;
	}
	if (!(new_file.buff = ft_strnew(0))) // I can even make this 0 if enough lines in gnlreadline
		return (NULL);
	new_file.fd = fd;
	if (!(new_element = ft_lstnew(&new_file, sizeof(t_filebuff)))) // free new_file.buff here?
		return (NULL);
	ft_lstadd(file_list, new_element);
	return ((t_filebuff*)new_element->content);
}

static ssize_t		ft_gnl_read_line(t_filebuff *file, const int fd)
{
	char	buff[BUFF_SIZE + 1];
	ssize_t	read_bytes;
	char	*temp;

	read_bytes = 1;
	//printf("%s\n", file->buff);
	while (read_bytes && !ft_strchr((const char *)(file->buff), '\n'))
	{
		ft_bzero(buff, BUFF_SIZE + 1);
		//printf("x\n");
		read_bytes = read(fd, buff, BUFF_SIZE);
		//printf("###%s###\n", buff);
		if (read_bytes == -1)
			return (-1);
		buff[read_bytes] = 0;
		temp = file->buff;
	//	printf("file->buff: %s\nbuff: %s\n\n\n", file->buff, buff);
		file->buff = ft_strjoin(file->buff, buff); //gotta check and free
		free(temp);
//		printf("file->buff: %ld\ntemp: %ld\n\n", (long)file->buff, (long)temp);
	//	printf("buff: %s ###\n", buff);
	//	printf("%s\n", file->buff);
		if (!(file->buff))
			return (-1);//maybe free?
	}
	//printf("%sx\n", file->buff);
	return (read_bytes);
}

int					get_next_line(const int fd, char **line)
{
	static t_list	*file_list;
	int				ret;
	t_filebuff		*file;
	char			*temp;
	char			*wow;

	if (!fd || !line || fd > GNL_MAX_FD)
		return (-1);
	if (!(file = ft_gnl_get_file(&file_list, fd)))
		return (-1);
	ret = ft_gnl_read_line(file, fd);
	*line = ft_strnew(ft_strclen(file->buff, '\n') + 1);
	wow = ft_memccpy(*line, file->buff, '\n', ft_strlen(file->buff) + 1);
	(*line)[ft_strlen(*line) - 1] = (*line)[ft_strlen(*line) - 1] == '\n' ?
		0 : (*line)[ft_strlen(*line) - 1];
	temp = file->buff;
	file->buff = ft_strdup(file->buff + ft_strclen(file->buff, '\n') + 1);//check malloc
	free(temp);
	if (ret > 0)
		return (1);
	return (ret);
}