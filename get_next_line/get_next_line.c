/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksappi <ksappi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 11:38:27 by ksappi            #+#    #+#             */
/*   Updated: 2019/10/22 15:58:07 by ksappi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <fcntl.h> //vitsiin
#include <stdio.h> //vitsiin

static t_filebuff		*gnl_get_file(t_list **file_list, const int fd)
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
	if (!(new_file.buff = ft_strnew(BUFF_SIZE + 1)))
		return (NULL);
	new_file.fd = fd;
	if (!(new_element = ft_lstnew(&new_file, sizeof(t_filebuff)))) // free new_file.buff here?
		return (NULL);
	ft_lstadd(file_list, new_element);
	return ((t_filebuff*)new_element->content);
}

static ssize_t		gnl_read_line(t_filebuff *file, const int fd)
{
	char	buff[BUFF_SIZE + 1];
	ssize_t	read_bytes;
	char	*temp;

	read_bytes = 1;
	while (read_bytes && !ft_strchr((const char *)(file->buff), '\n'))
	{
		read_bytes = read(fd, buff, BUFF_SIZE);
		if (read_bytes == -1)
			return (-1);
		buff[read_bytes] = 0;
		temp = file->buff;
		file->buff = ft_strjoin(file->buff, buff); //gotta check and free
		free(temp);
		if (!(file->buff))
			return (-1);//maybe free?
	}
	return (read_bytes);
}

int					get_next_line(const int fd, char **line)
{
	static t_list	*file_list;
	int				ret;
	t_filebuff		*file;
	char			*temp;

	if (!fd || !line)
		return (-1);
	if (!(file = gnl_get_file(&file_list, fd)))
		return (-1);
	ret = gnl_read_line(file, fd);
	*line = ft_strnew(ft_strclen(file->buff, '\n') + 1);
	ft_memccpy(*line, file->buff, '\n', strlen(file->buff) + 1);
	temp = file->buff;
	file->buff = ft_strdup(&(file->buff[ft_strclen + 1]));//check malloc
	free(temp);
	if (ret > 0)
		return (1);
	return (ret);
}

int main(void) // vitsiin
{
	char *line = malloc(1024);
	int file = open("get_next_line.h", O_RDONLY);
	printf("file: %d\n", file);
	int i = 1;
	while (i > 0)
	{
		i = get_next_line(file, &line);
		printf("%d: %s\n",i, line);
	}
	free(line);
	return (0);
}
