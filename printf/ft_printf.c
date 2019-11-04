/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksappi <ksappi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 15:57:13 by ksappi            #+#    #+#             */
/*   Updated: 2019/11/04 11:40:27 by ksappi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	pf_is_flag(char *c)
{ // I actually need to loop through here because order matters:
// %[parameter***$***][flags][width][.precision][length]type
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

static char	pf_expand_type(char c, t_pf_type type)
{
	if (c == 'c')
		return (PF_CHAR);
	if (c == 'd' || c == 'i')
		return (PF_INT);
	
}

static void	pf_type_init(s_pf_type *type)
{
	type->type = 0;
	ft_bzero(type->flags, PF_MAX_FLAGS * sizeof(char));
	type->precision = -1;
	type->width = -1;
	type->parameter = -1;
}

/*
** ft_format has to return length of the written string and point *str to
**		first char after format specifier conversion
*/
static int	pf_parse_format(char **str)
{
	t_pf_type	type;
	int			i;
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
	pf_type_init(&type);
	i = -1;
	while (i < PF_MAX_FLAGS - 1 && type.flags[++i] = pf_is_flag(*str))
		*str += (type.flags[i] % 10) * sizeof(char);
	type.type = ft_expand_type(**str, type);
	*str += (type.type % 10) * sizeof(char);
	
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
