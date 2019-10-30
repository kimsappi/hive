/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksappi <ksappi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 11:06:30 by ksappi            #+#    #+#             */
/*   Updated: 2019/10/29 14:05:30 by ksappi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft.h"
# define BUFF_SIZE 8
# define GNL_MAX_BUFF_SIZE 8000000
# define GNL_MAX_FD 4863

typedef struct	s_filebuff
{
	char		*buff;
	int			fd;
}				t_filebuff;

int				get_next_line(const int fd, char **line);

#endif
