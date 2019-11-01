/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksappi <ksappi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 15:45:48 by ksappi            #+#    #+#             */
/*   Updated: 2019/11/01 14:37:27 by ksappi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <fillit.h>

static char	fi_read_file(int fd)
{
	t_list	*pieces;
	char	rows;
	char	row;

	pieces = NULL;
	rows = 0;
	while (++rows < 5)
	{
		row = get_next_line(fd, &line);
		
	}
}

int	main(int argc, char **argv)
{
	int	fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			return (1);
		else
			fi_read_file(fd);
	}
	else
		ft_putendl("usage: fillit file_name");
	return (0); //return 1 if usage? Probably not but not sure
}
