/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan <yyan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:21:19 by yyan              #+#    #+#             */
/*   Updated: 2019/11/05 15:28:11 by yyan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		print_board(char **board, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_putendl(board[i]);
		i++;
	}
}

static int	check_piece(int size, t_piece *piece, char **board, t_coord coord)
{
	int rowtp;
	int coltp;
	int i;

	i = 0;
	while (i < 3)
	{
		rowtp = coord.row + piece->row[i];
		coltp = coord.col + piece->col[i];
		if (rowtp < 0 || rowtp >= size || coltp < 0 || coltp >= size)
			return (0);
		if (!(board[rowtp][coltp] == '.'))
			return (0);
		++i;
	}
	i = 0;
	board[coord.row][coord.col] = piece->letter;
	while (i < 3)
	{
		board[coord.row + piece->row[i]][coord.col + piece->col[i]] =
			piece->letter;
		i++;
	}
	return (1);
}

static void	reset_board(t_piece *piece, char **board, t_coord coord)
{
	int i;

	i = 0;
	board[coord.row][coord.col] = '.';
	while (i < 3)
	{
		board[coord.row + piece->row[i]][coord.col + piece->col[i]] = '.';
		i++;
	}
}

int			solve_board(t_piece *piece, int count, int size, char **board)
{
	t_coord	coord;

	coord.row = 0;
	if (count < 1)
		return (1);
	while (coord.row < size)
	{
		coord.col = 0;
		while (coord.col < size)
		{
			if (board[coord.row][coord.col] == '.')
				if (check_piece(size, piece, board, coord))
				{
					if (solve_board(piece + 1, count - 1, size, board))
						return (1);
					reset_board(piece, board, coord);
				}
			coord.col++;
		}
		coord.row++;
	}
	return (0);
}
