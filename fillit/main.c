/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksappi <ksappi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 13:20:34 by ksappi            #+#    #+#             */
/*   Updated: 2019/10/29 15:40:21 by ksappi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	fillit_place_piece(t_board *board, t_list *piece, int coordinate, char reset)
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
			if (!(board->board[coordinate / board->size]) && !(board->board[coordinate % board->size]))
			if (fillit_place_piece(board, piece, coordinate, 0))
			{
				if (fillit_solver(board, piece->next))
					return (1);
				else
					fillit_place_piece(board, piece, coordinate, 1);
			}
			++coordinate;
		}
	}
	return (0);
}