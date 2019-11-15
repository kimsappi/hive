/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan <yyan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 10:15:26 by ksappi            #+#    #+#             */
/*   Updated: 2019/11/05 15:20:45 by yyan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"

typedef struct	s_piece
{
	char	letter;
	char	row[3];
	char	col[3];
}				t_piece;

typedef struct	s_coord
{
	int		row;
	int		col;
}				t_coord;

int				solve_board(t_piece *piece, int count, int size, char **board);
void			print_board(char **board, int size);
int				fi_read_file(int fd, t_piece *pieces);
void			raise_error(void);

#endif
