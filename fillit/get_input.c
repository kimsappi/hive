/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan <yyan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:21:50 by yyan              #+#    #+#             */
/*   Updated: 2019/11/05 16:14:22 by yyan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	fi_check_block(char *buf)
{
	int i;
	int count;

	i = -1;
	count = 0;
	while (buf[++i])
	{
		if (buf[i] != '.' && buf[i] != '#' && buf[i] != '\n')
			raise_error();
		if (buf[i] == '\n')
		{
			if (i != 4 && i != 9 && i != 14 && i != 19 && i != 20)
				raise_error();
		}
		if (buf[i] == '#')
			count++;
	}
	if (buf[4] == '\n' && buf[9] == '\n' && buf[14] == '\n' && buf[19] == '\n')
	{
		if (buf[20] != '\0' && buf[20] == '\n')
			return (count);
		else if (buf[20] == '\0')
			return (count);
	}
	return (0);
}

static int	check_touch(int i, char *s)
{
	int touches;

	touches = 0;
	if (i - 5 >= 0)
		if (s[i - 5] == '#')
			++touches;
	if (i - 1 >= 0)
		if (s[i - 1] == '#')
			++touches;
	if (i + 1 < 20)
		if (s[i + 1] == '#')
			++touches;
	if (i + 5 < 20)
		if (s[i + 5] == '#')
			++touches;
	return (touches);
}

static char	get_coordinate(char *buf, t_piece *piece)
{
	int i;
	int current;
	int first;
	int touch;

	i = 0;
	touch = 0;
	first = ft_strclen(buf, '#');
	touch += check_touch(first, buf);
	current = first + 1;
	while (i < 3)
	{
		current += ft_strclen(buf + current, '#');
		piece->row[i] = current / 5 - first / 5;
		piece->col[i] = current % 5 - first % 5;
		touch += check_touch(current, buf);
		++i;
		++current;
	}
	if (touch != 6 && touch != 8)
		return (0);
	return (1);
}

int			fi_read_file(int fd, t_piece *pieces)
{
	char	buf[22];
	int		ret;
	int		count;

	ret = 21;
	count = 0;
	while (ret == 21 && count < 26)
	{
		ret = read(fd, buf, 21);
		buf[ret] = '\0';
		if (fi_check_block(buf) == 4 && (ret == 21 || ret == 20))
		{
			if (!get_coordinate(buf, &pieces[count]))
				raise_error();
		}
		else
			raise_error();
		pieces[count].letter = 'A' + count;
		count++;
	}
	if (ret == 21)
		raise_error();
	return (count);
}
