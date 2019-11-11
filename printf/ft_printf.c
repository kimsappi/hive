/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksappi <ksappi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 15:57:13 by ksappi            #+#    #+#             */
/*   Updated: 2019/11/11 17:35:49 by ksappi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> //pois
/*
static void	pf_get_parameter(const char **str, t_pf_type *type)
{
	size_t	until_sign;
	size_t	i;
	char	*new_pos;

	if ((new_pos = ft_strchr(*str, '$')))
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
*/
static char	pf_is_flag(const char *str, t_pf_type *type)
{ // I actually need to loop through here because order matters:
// %[parameter***$***][flags][width][.precision][length (hh, ll, L)]type
	if (*str == 'h')
	{
		if (*(str + 1) == 'h')
			return (PF_HH);
		else
			return (PF_H);
	}
	if (*str == 'l')
	{
		if (*(str + 1) == 'l')
			return (PF_LL);
		else
			return (PF_L);
	}
	if (*str == 'L' || *str == ' ')
		return (*str == 'L' ? PF_CPTL_L : PF_SPACE);
	if (*str == '#' || *str == '0')
		return (*str == '#' ? PF_HASH : PF_ZERO);
	if (*str == '-' || *str == '+')
		return (*str == '-' ? PF_MINUS : PF_PLUS);
	//printf("\nno flags, char: %c\n", *str);
	return (0);
}

static void	pf_type_init(t_pf_type *type)
{
	type->type = 0;
	ft_bzero(type->flags, 6 * sizeof(char));
	type->precision = -1;
	type->width = -1;
//	type->parameter = -1;
}

static void	pf_get_width(const char **str, t_pf_type *type)
{
	if (ft_isdigit(**str))
	{
		type->width = ft_atoi(*str);
		while (ft_isdigit(**str))
			++(*str);
	}
}

static void	pf_get_precision(const char **str, t_pf_type *type) //will have to return something if e.g. "%.d"
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

static size_t	pf_put_char(t_pf_type type, va_list params)
{
	int c;

	c = va_arg(params, int);
	(void)type;
	return (write(1, &c, 1));
}

static size_t	pf_put_str(t_pf_type type, va_list params)
{
	char *str;

	str = va_arg(params, char*);
	(void)type;
	return (write(1, str, ft_strlen(str)));
}

static size_t	pf_put_int(t_pf_type type, va_list params)
{
	int nb;

	nb = va_arg(params, int);
	(void)type;
	return (write(1, &nb, 1));
}

static size_t	pf_print_type(char c, t_pf_type type, va_list params)
{
	if (c == 'c')
		return (pf_put_char(type, params));
	if (c == 's')
		return (pf_put_str(type, params));
	if (c == 'd' || c == 'i')
		return (pf_put_int(type, params));
/*	if (c == 'u')
		return (pf_put_uint_base(type, params, 10, 0));
	if (c == 'o')
		return (pf_put_uint_base(type, params, 8, 0));
	if (c == 'x' || c == 'X')
		return (pf_put_uint_base(type, params, 8, c == 'X' ? 1 : 0));
*/	return (0);
}

/*
** ft_format has to return length of the written string and point *str to
**		first char after format specifier conversion
*/
static int	pf_parse_format(const char **str, va_list params)
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
	//pf_get_parameter(str, &type);
	while (i < 4 && (type.flags[++i] = pf_is_flag(*str, &type)))
		*str += (type.flags[i] % 10);
//	printf("\ncheck 1, char: %c\n", **str);
	pf_get_width(str, &type);
//	printf("\ncheck 2, char: %c\n", **str);
	pf_get_precision(str, &type);
//	printf("\ncheck 3, char: %c\n", **str);
	pf_print_type(**str, type, params);
	++(*str);
}

int	ft_printf(const char *format, ...)
{
	//t_list	*head;
	//t_list	*current;
	va_list	params;
	int		substr_len;
	int		length;

	length = 0;
	//head = NULL;
	if (format)
	{
		va_start(params, format);
		while ((substr_len = ft_strclen(format, '%')))
		{
			length += substr_len;
			write(1, format, substr_len);
			format += substr_len;
			if (!(substr_len = pf_parse_format(&format, params)))
				return (length);
			length += substr_len;
		}
	}
	va_end(params);
	return (length);
}
