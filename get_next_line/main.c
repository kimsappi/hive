/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksappi <ksappi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 11:38:27 by ksappi            #+#    #+#             */
/*   Updated: 2019/10/24 11:05:41 by ksappi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <fcntl.h> //vitsiin
#include <stdio.h> //vitsiin

void read_one_file(void) // vitsiin
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
	close(file);
}

void read_2_files(void)
{
	char *line = malloc(1024);
	int file = open("get_next_line.h", O_RDONLY);
	int file2 = open("main.c", O_RDONLY);
	printf("file: %d\n", file);
	int i = 1;
	int j = 1;
	while (i > 0 || j > 0)
	{
		i = get_next_line(file, &line);
		printf("%d: %s\n",i, line);
		j = get_next_line(file2, &line);
		printf("%d: %s\n",i, line);
	}
	free(line);
	close(file);
	close(file2);
}

int main(int argc, char **argv) {
	if (argc == 1)
		read_one_file();
	else
		read_2_files();
	return (0);
}