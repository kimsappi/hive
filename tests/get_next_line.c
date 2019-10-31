/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksappi <ksappi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 11:38:27 by ksappi            #+#    #+#             */
/*   Updated: 2019/10/31 14:04:23 by ksappi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <fcntl.h> //vitsiin
#include <stdio.h> //vitsiin

void read_one_file(void) // vitsiin
{
	char *line;
	int file = open("get_next_line.h", O_RDONLY);
	printf("file: %d\n", file);
	int i = 1;
	while (i > 0)
	{
		i = get_next_line(file, &line);
		printf("%d: %s\n",i, line);
		free(line);
	}
	close(file);
}

void read_2_files(void)
{
	char *line;
	int file = open("get_next_line.h", O_RDONLY);
	int file2 = open("main.c", O_RDONLY);
	printf("file: %d\n", file);
	int i = 1;
	int j = 1;
	while (i > 0 || j > 0)
	{
		i = get_next_line(file, &line);
		printf("%d: %s\n",i, line);
		free(line);
		j = get_next_line(file2, &line);
		printf("%d: %s\n",j, line);
		free(line);
	}
	close(file);
	close(file2);
}

void	read_stdin(int fd)
{
	char *line;
	int i = 1;
	while (i > 0)
	{
		i = get_next_line(fd, &line);
		printf("%d: %s\n",i, line);
		free(line);
	}
}

int main(int argc, char **argv) {
	(void)argv;
	if (argc == 1)
		read_one_file();
	else if (argc == 2)
		read_2_files();
	else if (argc == 3)
		read_stdin(1);
	else
		read_stdin(0);
	while (1);
	return (0);
}
