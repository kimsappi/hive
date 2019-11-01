/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksappi <ksappi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 13:20:34 by ksappi            #+#    #+#             */
/*   Updated: 2019/11/01 10:40:50 by ksappi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// these fi_get_* functions aren't really needed if we use board[size][size]
static int	fi_get_column(t_board *board, int coordinate)
{
	return (coordinate % board->size);
}

static int	fi_get_row(t_board *board, int coordinate)
{
	return (coordinate / board->size);
}

static char	fi_place_piece(t_board **board, t_list *piece, int coordinate, char reset)
{
	int i;
	int new_coord;
	int	new_coords[3];

	i = -1;
	if (reset)
	while (++i < 3)
	{
		new_coord = coordinate + (piece->content).x[i] + (piece->content).y[i] * board->size;
		if (reset)
		{
			if (new_coord < coordinate || (board->board)[new_coord] ||
				coordinate + (piece->content).x[i] / board->size != coordinate / board->size)
				return (0);
		}
		new_coords[i] = new_coord;
	}
	i = -1;
	while (++i < 3)
	{
		if (reset)
			(board->board)[new_coords[i]] = 0;
		else
			(board->board)[new_coords[i]] = piece->character;
	}
	return (1);
}

int			fillit_solver(t_board *board, t_list *piece)
{
	int coordinate;

	if (!piece)
		return (1);
	
	y = 0;
	while (coordinate < board->size)
	{
		while (coordinate < board->size)
		{
			if (!(board->board[fi_get_row(board, coordinate)]) &&
				!(board->board[fi_get_column(board, coordinate]))
				; // why did I do this
			if (fi_place_piece(board, piece, coordinate, 0))
			{
				if (fillit_solver(board, piece->next))
					return (1);
				else
					fi_place_piece(board, piece, coordinate, 1);
			}
			++coordinate;
		}
	}
	return (0);
}