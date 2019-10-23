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
