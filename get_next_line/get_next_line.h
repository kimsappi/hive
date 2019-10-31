/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksappi <ksappi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 11:06:30 by ksappi            #+#    #+#             */
/*   Updated: 2019/10/31 10:56:07 by ksappi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft.h"
# define BUFF_SIZE 100
# define MAX_BUFF 7900000
# define MAX_FD 4863

int				get_next_line(const int fd, char **line);

#endif
