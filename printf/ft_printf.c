/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksappi <ksappi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 15:57:13 by ksappi            #+#    #+#             */
/*   Updated: 2019/11/11 11:17:18 by ksappi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_get_parameter(char **str, t_pf_type *type)
{
	size_t	until_sign;
	size_t	i;
	char	*new_pos;

	if (new_pos = ft_strchr(*str, '$'))
	{
		until_sign = ft_strclen(*str, '$');
		i = -1;
		while (++i < until_sign)
			if (!ft_isdigit(*str[i]))
				return ;
		type->parameter = ft_atoi(*str);
		*str = new_pos + 1;
	}
}

static char	pf_is_flag(char *str, t_pf_type *type)
{ // I actually need to loop through here because order matters:
// %[parameter***$***][flags][width][.precision][length (hh, ll, L)]type
	if (*str == 'h')
		if (*(str + 1) == 'h')
			return (PF_HH);
		else
			return (PF_H);
	if (*str == 'l')
		if (*(c + 1) == 'l')
			return (PF_LL);
		else
			return (PF_L);
	if (*str == 'L' || *str == ' ')
		return (*str == 'L' ? PF_CPTL_L : PF_SPACE);
	if (*str == '#' || *str == '0')
		return (*str == '#' ? PF_HASH : PF_ZERO);
	if (*str == '-' || *str == '+');
		return (*str == '-' ? PF_MINUS : PF_PLUS);
	return (0);
}

static char	pf_expand_type(char c, t_pf_type type)
{
	if (c == 'c')
		return (PF_CHAR);
	if (c == 'd' || c == 'i')
		return (PF_INT);
	
}

static void	pf_type_init(t_pf_type *type)
{
	type->type = 0;
	ft_bzero(type->flags, 6 * sizeof(char));
	type->precision = -1;
	type->width = -1;
	type->parameter = -1;
}

static void	pf_get_width(char **str, t_pf_type *type)
{
	if (ft_isdigit(**str))
	{
		type->width = ft_atoi(*str);
		while (ft_isdigit(**str))
			++(*str);
	}
}

static void	pf_get_precision(char **str, t_pf_type *type) //will have to return something if e.g. "%.d"
{
	if (**str == '.')
	{
		++(*str);
		if (ft_isdigit(**str))
		{
			type->precision = ft_atoi(*str);
			while (ft_isdigit(**str))
				++(*str);
		}
	}
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

	if (!*((*str)++)) //yooooo
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
	pf_get_parameter(&str, &type);
	while (i < 4 && type.flags[++i] = pf_is_flag(*str, &type))
		*str += (type.flags[i] % 10);
	pf_get_width(str, &type);
	pf_get_precision(str, &type);
	type.type = pf_expand_type(**str, type);
	*str += (type.type % 10);
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