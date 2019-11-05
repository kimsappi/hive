/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksappi <ksappi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 15:45:48 by ksappi            #+#    #+#             */
/*   Updated: 2019/11/04 12:03:05 by ksappi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <fillit.h>

static char	fi_check_row_validity(char *row)
{
	int length;

	length = 0;
	while (*row)
	{
		if (++length > 4)
			return (0);
		if (*row != '.' && *row != '#')
			return (0);
		++row;	
	}
	return (length == 4 ? 1 : 0);
}

static char	fi_read_file(int fd)
{
	t_list	*pieces;
	int		row;
	char	*rows[4];

	pieces = NULL;
	row = -1;
	while (++row < 5)
	{
		get_next_line(fd, rows[row]);
		if (!fi_check_row_validity(rows[row]))
			exit(42);
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
