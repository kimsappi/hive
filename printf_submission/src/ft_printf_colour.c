/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_colour.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksappi <ksappi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 03:43:13 by ksappi            #+#    #+#             */
/*   Updated: 2020/02/03 10:32:16 by ksappi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	pf_print_color(int foreground, int fd, int color)
{
	int printed_len;

	printed_len = ft_printf_fd(fd, "\033[");
	if (!(foreground % 2))
		printed_len += ft_printf_fd(fd, "%dm", 40 + color);
	else
	{
		printed_len += ft_printf_fd(fd, "%d;%dm", foreground / 10, 90 + color);
	}
	return (printed_len);
}

static int	pf_check_color(char **str, char *color, int foreground)
{
	int	length;

	length = ft_strlen(color);
	if (ft_strnstr(*str + 1, color, length) &&
		*(*str + 1 + length) == (foreground ? ']' : '}'))
	{
		*str += length + 2;
		return (foreground + 10);
	}
	if (ft_strnstr(*str + 2, color, length) &&
		*(*str + 2 + length) == (foreground ? ']' : '}'))
	{
		*str += length + 3;
		return (foreground + 20);
	}
	return (0);
}

int			pf_put_color(char **str, char bracket, int fd)
{
	int			foreground;
	int			i;
	static char	*color_strings[8] = {"black", "red", "green", "yellow", "blue",
		"magenta", "cyan", "white"};

	foreground = (bracket == '[' ? 1 : 0);
	if (!ft_strchr(*str, foreground ? ']' : '}'))
		return (0);
	if (*(*str + 1) == (foreground ? ']' : '}'))
	{
		*str += 2;
		return ft_printf_fd(fd, "\033[0m");
	}
	i = -1;
	while (++i < 8)
	{
		if (ft_strnstr(*str, color_strings[i], ft_strlen(color_strings[i]) + 2))
			break ;
	}
	if (i == 9)
		return (0);
	foreground = pf_check_color(str, color_strings[i], foreground);
	if (foreground)
		return (pf_print_color(foreground - 10, fd, i));
	return (0);
}