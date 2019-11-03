/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksappi <ksappi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 15:57:13 by ksappi            #+#    #+#             */
/*   Updated: 2019/11/03 15:05:45 by ksappi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	pf_is_flag(char *c)
{
	if (*c == 'h')
		if (*(c + 1) == 'h')
			return (PF_HH);
		else
			return (PF_H);
	if (*c == 'l')
		if (*(c + 1) == 'l')
			return (PF_LL);
		else
			return (PF_L);
	if (*c == 'L' || *c == ' ')
		return (*c == 'L' ? PF_CPTL_L : PF_SPACE);
	if (*c == '#' || *c == '0')
		return (*c == '#' ? PF_HASH : PF_ZERO);
	if (*c == '-' || *c == '+');
		return (*c == '-' ? PF_MINUS : PF_PLUS);
	//need to handle precision && field width here
	return (0);
}

static char	pf_expand_type(char c, char *flags)
{
	if (c == 'c')
		return (PF_CHAR);
	if (c == 'd' || c == 'i')
		return (PF_INT);
	
}

/*
** ft_format has to return length of the written string and point *str to
**		first char after format specifier conversion
*/
static int	pf_parse_format(char **str)
{
	char	*flags[10];
	char	type;
	int		i;
	//char	color;

	if (!*((*str)++))
		return (0);
	if (!**str)
		return (-1);
		// '\0' found after '%'?? clang warning: "incomplete format specifier". Pragma? #error?
	if (**str == '%')
	{
		++(*str);
		return (write(1, "%", 1));
	}
	ft_bzero(flags, 10 * sizeof(char));
	i = -1;
	while (i < 9 && flags[++i] = pf_is_flag(*str))
		*str += (flags[i] % 10) * sizeof(char);
	type = ft_expand_type(**str, flags);
	*str += (type % 10) * sizeof(char);
	
}

int	ft_printf(const char *format, ...)
{
	//t_list	*head;
	//t_list	*current;
	int		substr_len;
	int		length;

	length = 0;
	//head = NULL;
	if (format)
	{
		while (substr_len = ft_strclen(format, '%'))
		{
			length += substr_len;
			write(1, format, substr_len);
			format += substr_len;
			if (!(substr_len = pf_parse_format(&format)))
				return (length);
			length += substr_len;
		}
	}
	return (length);
}
