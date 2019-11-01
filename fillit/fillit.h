/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksappi <ksappi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 10:15:26 by ksappi            #+#    #+#             */
/*   Updated: 2019/11/01 10:35:54 by ksappi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"

typedef struct	s_piece
{
	char	letter; //letter that must be placed
	char	x[3]; //x coordinate of each square relative to the first square read
	char	y[3]; //same but y, same order
	char	height; // total height of piece relative to first square read?
					// #### = height 0?
	char	width; // total width of piece relative to first square read
					// #### = width 3?
}				t_piece;

typedef struct	s_board
{
	char	**board;
	char	size;
}				t_board;

int				fillit_solver(t_board *board, t_list *piece);

#endif