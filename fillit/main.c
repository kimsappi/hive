/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan <yyan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 15:45:48 by ksappi            #+#    #+#             */
/*   Updated: 2019/11/05 16:42:17 by ksappi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fillit.h"

void		raise_error(void)
{
	ft_putendl("error");
	exit(1);
}

static char	**get_board(int size)
{
	int		i;
	char	**board;

	i = 0;
	if (!(board = (char**)malloc(sizeof(char*) * size)))
		raise_error();
	while (i < size)
	{
		board[i] = (char*)malloc(sizeof(char) * (size + 1));
		if (!board[i])
			raise_error();
		board[i][size] = '\0';
		ft_memset(board[i], '.', size);
		i++;
	}
	return (board);
}

static void	free_board(char **board, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_strdel(&board[i]);
		i++;
	}
	free(board);
	board = NULL;
}

static void	fill_it(int count, t_piece *piece)
{
	char	**board;
	int		size;
	int		check;

	size = ft_ceil_sqrt(count * 4);
	check = 0;
	while (!check)
	{
		board = get_board(size);
		check = solve_board(piece, count, size, board);
		if (check)
			print_board(board, size);
		free_board(board, size);
		size++;
	}
}

int			main(int argc, char **argv)
{
	int		fd;
	t_piece	pieces[26];
	int		count;

	count = 0;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			raise_error();
		else
			count = fi_read_file(fd, pieces);
		if (close(fd) < 0)
			raise_error();
		fd = 0;
		fill_it(count, pieces);
	}
	else
		ft_putendl("usage: fillit file_name");
	while(1);
	return (0);
}
