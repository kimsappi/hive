/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksappi <ksappi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 15:57:13 by ksappi            #+#    #+#             */
/*   Updated: 2019/11/26 16:32:57 by ksappi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**static void	pf_get_parameter(const char **str, t_pf_type *type)
**{
**	int	until_sign;
**	int	i;
**	char	*new_pos;
**
**	if ((new_pos = ft_strchr(*str, '$')))
**	{
**		until_sign = ft_strclen(*str, '$');
**		i = -1;
**		while (++i < until_sign)
**			if (!ft_isdigit(*str[i]))
**				return ;
**		type->parameter = ft_atoi(*str);
**		*str = new_pos + 1;
**	}
**}
*/

/*
**static pf_put_float(t_pf_type type, va_list params, char capitalise)
**{
**	long double	nb;
**	long double	temp;
**	int	len;
**	char	str[1000];
**	int		i;
**
**	//divide by 10 until nb = 0;
**	//put to string until last digit (i == 0)
**	//get digits by multiplying by 10 (but how without %?)
**	if (type.length == PRINTF_CPTL_L) {
**		nb = va_arg(params, long double); printf("%Lf\n", nb); }
**	else {
**		nb = (long double)va_arg(params, double);printf("%f\n", (double)nb); }
**	i = 0;
**	if (nb < 0)
**	{
**		str[0] = '-';
**		++i;
**		nb = -nb;
**	}
**	ft_bzero(str, 1000);
**	temp = nb;
**	len = 0;
**	while (temp / 10.0 > 1.0)
**	{
**		temp /= 10.0;
**		++len;
**		//printf("%Lf", temp);
**	}
**	//printf("%Lf\n", nb);
**	printf("len of integer part: %lu\n", len);
**}
*/

static int	pf_print_type(char c, t_pf_type type, va_list params)
{
	if (c == 'c')
		return (pf_put_char(type, params));
	if (c == 's')
		return (pf_put_str(type, params));
	if (c == 'd' || c == 'i')
		return (pf_put_int(type, params));
	if (c == 'u')
		return (pf_put_uint_base(type, params, 10, 0));
	if (c == 'o')
		return (pf_put_uint_base(type, params, 8, 0));
	if (c == 'x' || c == 'X')
		return (pf_put_uint_base(type, params, 16, c == 'X' ? 1 : 0));
	if (c == 'p')
		return (pf_put_ptr(type, params));
	if (c == 'f' || c == 'F')
		return (pf_put_float(type, params));
	if (c == '%')
		return (pf_put_percent(type));
	return (-1);
}

/*
** ft_parse_format has to return length of the written string and point *str to
**		first char after format specifier conversion
*/

static int	pf_parse_format(const char **str, va_list params)
{
	t_pf_type	type;
	int			len;

	if (!(**str) || !*((*str)++))
		return (0);
	if (!**str)
		return (-1);
	if (**str == '%')
	{
		++(*str);
		return (write(1, "%", 1));
	}
	pf_type_init(&type);
	while (pf_is_flag(*str, &type))
		++(*str);
	pf_get_width(str, &type);
	pf_get_precision(str, &type);
	pf_get_length(str, &type);
	len = pf_print_type(**str, type, params);
	(len > -1 && **str) ? ++(*str) : 0;
	return (len > -1 ? len : 0);
}

int			ft_printf(const char *format, ...)
{
	va_list	params;
	int		substr_len;
	int		length;

	length = 0;
	if (format)
	{
		va_start(params, format);
		while (*format)
		{
			substr_len = ft_strclen(format, '%');
			length += substr_len;
			write(1, format, substr_len);
			format += substr_len;
			if ((substr_len = pf_parse_format(&format, params)) > 0)
				length += substr_len;
		}
	}
	va_end(params);
	return (length);
}
