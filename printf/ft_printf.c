/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksappi <ksappi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 15:57:13 by ksappi            #+#    #+#             */
/*   Updated: 2019/11/12 13:42:35 by ksappi           ###   ########.fr       */
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
	if (*str == ' ' || *str == '#' || *str == '0' || *str == '-' || *str == '+')
		return (*str);
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

static void pf_get_length(const char **str, t_pf_type *type)
{
	if (**str == 'h') //lenghts dont belong
	{
		type->length = PRINTF_H;
		++(*str);
		if (**str == 'h')
		{
			++(*str);
			type->length = PRINTF_HH;
		}
	}
	else if (**str == 'l')
	{
		++(*str);
		type->length = PRINTF_L;
		if (**str == 'l')
		{
			++(*str);
			type->length = PRINTF_LL;
		}
	}
	else if (**str == 'L')
	{
		++(*str);
		type->length = PRINTF_CPTL_L;
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

static size_t	pf_pre_pad(t_pf_type type, size_t len)
{
	int		i;
	char	pad_char;
	
	pad_char = ' ';
	i = -1;
	while (type.flags[++i])
	{
		if (type.flags[i] == '-')
			return (0);
		if (type.flags[i] == '0')
			pad_char = '0';
	}
	i = -1;
	while (++i + len < type.width && type.width > 0)
		write(1, &pad_char, 1);
	return (i);
}

static size_t	pf_post_pad(t_pf_type type, size_t len)
{
	int		i;
	char	flag_found;
	
	i = -1;
	flag_found = 0;
	while (type.flags[++i])
	{
		if (type.flags[i] == '-')
			flag_found = 1;
	}
	if (!flag_found)
		return (0);
	i = -1;
	while (++i + len < type.width && type.width > 0) 
		write(1, " ", 1);
	return (i);
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
	int		nb;
	char	*str;
	size_t	len;

	nb = va_arg(params, int);
	if (!(str = ft_itoa(nb)))
		return (-1);
	len = ft_strlen(str);
	pf_pre_pad(type, len);
	write(1, str, len);
	pf_post_pad(type, len);
	free(str);
	return (ft_strlen(str));
}

/*
 * Returns string with result of base conversion nb(decimal) to nb(base)
*/
char	*ft_itoa_base(unsigned int nb, char base, char capitalise)
{
	char			*str;
	char			digits[16];
	char			len;
	unsigned int	nb_copy;
	
	nb_copy = nb;
	len = (nb == 0 ? 1 : 0);
	while ((nb_copy = nb_copy / base) > 0)
		++len;
	if (base < 2 || base > 16 || !(str = ft_strnew((size_t)len)))
		return (NULL);
	if (capitalise)
		ft_memcpy(digits, "0123456789ABCDEF", 16 * sizeof(char));
	else
		ft_memcpy(digits, "0123456789abcdef", 16 * sizeof(char));
	while (len > -1)
	{
		str[len] = digits[nb % base];
		nb /= base;
		--len;
	}
	return (str);
}

static size_t	pf_put_uint_base(t_pf_type type, va_list params, char base, char capitalise)
{
	char			*str;
	unsigned int	nb;
	size_t			len;
	size_t			ret;

	nb = va_arg(params, unsigned int);
	if (!(str = ft_itoa_base(nb, base, capitalise)))
		return (0);
	len = ft_strlen(str);
	ret = len + pf_pre_pad(type, len);
	printf("%s", str);
	write(1, str, len);
	ret += pf_post_pad(type, len);
	free(str);
	return (ret);
}

static size_t	pf_print_type(char c, t_pf_type type, va_list params)
{
	//printf("type: %c\n", c);
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
//	if (c == 'f')
//		return (pf_put_float(type, params));
	return (0);
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
		++(*str);
//	printf("\ncheck 1, char: %c\n", **str);
	pf_get_width(str, &type);
//	printf("\ncheck 2, char: %c\n", **str);
	pf_get_precision(str, &type);
	pf_get_length(str, &type);
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
		//printf("len before %%: %lu\n", ft_strclen(format, '%'));
		while (*format)
		{
			substr_len = ft_strclen(format, '%');
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
