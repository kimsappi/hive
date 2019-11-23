/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksappi <ksappi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 15:57:13 by ksappi            #+#    #+#             */
/*   Updated: 2019/11/23 11:58:20 by ksappi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> //pois
/*
static void	pf_get_parameter(const char **str, t_pf_type *type)
{
	int	until_sign;
	int	i;
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

static char		ft_strcat_and_free(char *s1, char *s2)
{
	if (!s2)
		return (0);
	else
	{
		ft_strcat(s1, s2);
		free(s2);
		return (1);
	}
}

static char	pf_has_flag(char *flags, char flag)
{
	int	i;

	i = -1;
	while (++i < 6)
	{
		if (flags[i] == flag)
			return (1);
	}
	return (0);
}

static char	pf_is_flag(const char *str, t_pf_type *type)
{ // I actually need to loop through here because order matters:
// %[parameter***$***][flags][width][.precision][length (hh, ll, L)]type
	if (*str == '+' || *str == ' ')// || *str == '0') // added *str == '0' to try to fix int
	{
		if (!(*str == ' ' && type->sign))
			type->sign = *str;
		return (*str);
	}
	if (*str == ' ' || *str == '#' || *str == '0' || *str == '-' || *str == '+')
		return (*str);
	//printf("\nno flags, char: %c\n", *str);
	return (0);
}

static void	pf_type_init(t_pf_type *type)
{
	type->type = 0;
	ft_bzero(type->flags, 6 * sizeof(char));
	ft_bzero(type->uint_sign, 3 * sizeof(char));
	type->precision = -1;
	type->width = -1;
	type->length = -1;
	type->sign = 0;
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
	if (**str == 'h')
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
	(**str) ? type->type = **str : 0;
}

static void	pf_get_precision(const char **str, t_pf_type *type) //will have to return something if e.g. "%.d"
{
	if (**str == '.')
	{
		++(*str);
		//if (ft_isdigit(**str))
		if (**str)
		{
			type->precision = ft_atoi(*str);
			while (ft_isdigit(**str))
				++(*str);
		}
	}
}

static int	pf_pre_pad(t_pf_type type, int len, char allow_flags)
{
	int		pad_len;
	char	pad_char;
	
	pad_char = ' ';
	if (pf_has_flag(type.flags, '-'))
	{
		if (type.sign)
			return (write(1, &type.sign, 1));
		return (0);
	}
	if (pf_has_flag(type.flags, '0') && allow_flags)
	{
		pad_char = '0';
		if (!(type.precision < type.width && type.precision > -1))
			type.sign ? write(1, &type.sign, 1) : 0;
	}
	if (type.precision < type.width && type.precision > -1)
		pad_char = ' ';
	pad_len = -1 + (type.sign / ' ') * allow_flags;
	while (++pad_len + len < (int)type.width && type.width > 0)
		write(1, &pad_char, 1);
	if (type.sign && pad_char == ' ' && allow_flags)
		write(1, &type.sign, 1);
	return (pad_len);
}

static int	pf_post_pad(t_pf_type type, int len)
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
	while (++i + len < (int)type.width && type.width > 0) 
		write(1, " ", 1);
	return (i);
}

static int	pf_put_char(t_pf_type type, va_list params)
{
	int c;
	int printed_len;

	c = va_arg(params, int);
	printed_len = pf_pre_pad(type, 1, 0);
	printed_len += write(1, &c, 1);
	printed_len += pf_post_pad(type, printed_len);
	return (printed_len);
}

static int	pf_put_str(t_pf_type type, va_list params)
{
	char	*str;
	int		len;
	int		printed_len;

	str = va_arg(params, char*);
	if (!str)
		return (write(1, "(null)", 6));
	len = ft_strlen(str);
	if (type.precision != -1 && type.precision < len)
		len = type.precision;
	printed_len = pf_pre_pad(type, len, 0);
	printed_len += write(1, str, len);
	printed_len += pf_post_pad(type, printed_len);
	return (printed_len);
}

static long long	pf_get_int(t_pf_type type, va_list params)
{
	long long	nb;

	if (type.length == PRINTF_H)
		nb = (long long)(short)va_arg(params, int);
	if (type.length == PRINTF_HH)
		nb = (long long)(char)va_arg(params, int);
	if (type.length == PRINTF_L)
		nb = (long long)va_arg(params, long);
	if (type.length == PRINTF_LL)
		nb = (long long)va_arg(params, long long);
	if (type.length == -1)
		nb = (long long)va_arg(params, int);
	return (nb);
}

static unsigned long long	pf_get_uint(t_pf_type type, va_list params)
{
	long long	nb;

	if (type.length == PRINTF_H)
		nb = (unsigned long long)(unsigned short)va_arg(params, unsigned int);
	if (type.length == PRINTF_HH)
		nb = (unsigned long long)(unsigned char)va_arg(params, unsigned int);
	if (type.length == PRINTF_L)
		nb = (unsigned long long)va_arg(params, unsigned long);
	if (type.length == PRINTF_LL)
		nb = (unsigned long long)va_arg(params, unsigned long long);
	if (type.length == -1)
		nb = (unsigned long long)va_arg(params, unsigned int);
	return (nb);
}

static char	*pf_int_to_string(t_pf_type type, long long nb)
{
	char	*str;
	int		len;
	char	negative;
	char	*str_padded;

	if (!(str = ft_lltoa(nb)))
		return (NULL);
	len = ft_strlen(str);
	negative = str[0] == '-' ? 1 : 0;
	str_padded = str;
	if (type.precision > len - negative)
	{
		if ((str_padded = ft_strnew(type.precision + negative)))
		{
			ft_memset(str_padded, '0', type.precision + negative);
			ft_strcpy(str_padded + type.precision + 2 * negative - len, str + negative);
			//printf("type.precision + negative - len: %d\n", type.precision + negative - len);
		}
		if (str_padded && negative)
			str_padded[0] = '-';
		free(str);
	}
	return (str_padded);
}

static int	pf_put_int(t_pf_type type, va_list params)
{
	long long	nb;
	char		*str;
	int			len;
	char		negative;
	int			printed_len;

	nb = pf_get_int(type, params);
	if (!(str = pf_int_to_string(type, nb)))
		return (-1);
	len = ft_strlen(str);
		//printf("wowzer: %d\n", type.precision);
	if (!type.precision && !nb)
	{
		len = 0;
		str[0] = 0;
	}
	printed_len = len;
	negative = str[0] == '-' ? 1 : 0;
	negative ? type.sign = '-' : 0;
	printed_len += pf_pre_pad(type, len - negative, 1);
	//printf("\nasd: %d %d %d %s\n", printed_len, len, type.width, str);
	write(1, str + negative, len - negative);
	printed_len += pf_post_pad(type, printed_len - negative);
	free(str);
	return (printed_len - negative);
}

/*
 * Returns string with result of base conversion nb(decimal) to nb(base)
*/
char	*ft_itoa_base(unsigned long long nb, char base, char capitalise)
{
	char				*str;
	char				digits[16];
	int					len;
	unsigned long long	nb_copy;
	
	nb_copy = nb;
	//len = (nb == 0 ? 1 : 0); Removing this fixed 00 problem.
	len = 0;
	while ((nb_copy /= base) > 0)
		++len;
	if (base < 2 || base > 16 || !(str = ft_strnew(len + 1)))
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

static char	*pf_uint_to_string(t_pf_type type, unsigned long long nb, char base, char capitalise)
{
	char	*str;
	int		len;
	char	*str_padded;

	if (!(str = ft_itoa_base(nb, base, capitalise)))
		return (NULL);
	len = ft_strlen(str);
	str_padded = str;
	if (type.precision > len)
	{
		if ((str_padded = ft_strnew(type.precision)))
		{
			ft_memset(str_padded, '0', type.precision);
			ft_strcpy(str_padded + type.precision - len, str);
			//printf("type.precision + negative - len: %d\n", type.precision + negative - len);
		}
		free(str);
	}
	return (str_padded);
}

static int	pf_pre_pad_uint_base(t_pf_type type, int len, char base, char capitalise)
{
	int		i;
	char	pad_char;
	int		printed_len;
	
	if (base == 16 && pf_has_flag(type.flags, '#'))
		ft_strcpy(type.uint_sign, capitalise ? "0X" : "0x");
	if (base == 8 && pf_has_flag(type.flags, '#'))
		ft_strcpy(type.uint_sign, "0");
	pad_char = ' ';
	printed_len = 0;
	if (pf_has_flag(type.flags, '-'))
		return (write(1, type.uint_sign, ft_strlen(type.uint_sign)));
	if (pf_has_flag(type.flags, '0') && len)
	{
		pad_char = '0';
		printed_len = write(1, type.uint_sign, ft_strlen(type.uint_sign));
	}
	i = -1 + ft_strlen(type.uint_sign);
	while (++i + len < (int)type.width && type.width > 0)
		printed_len += write(1, &pad_char, 1);
	if (!(pf_has_flag(type.flags, '0')) && ft_strlen(type.uint_sign) && len)
		printed_len += write (1, type.uint_sign, ft_strlen(type.uint_sign));
	return (printed_len);
}

static int	pf_put_uint_base(t_pf_type type, va_list params, char base, char capitalise)
{
	char				*str;
	unsigned long long	nb;
	int					len;
	int					ret;

	//nb = va_arg(params, unsigned long long); //
	nb = (unsigned long long)pf_get_uint(type, params);
	if (!(str = pf_uint_to_string(type, nb, base, capitalise)))
		return (0);
	len = ft_strlen(str);
	if (!type.precision && !nb && (!pf_has_flag(type.flags, '#') || base == 16))
	{
		len = 0;
		str[0] = 0;
	}
	if (str[0] == '0' && pf_has_flag(type.flags, '#'))
	{
		ret = -1;
		while (++ret < 6)
			type.flags[ret] == '#' ? type.flags[ret] = 0 : 0;
	}
	ret = len + pf_pre_pad_uint_base(type, len, base, capitalise);
	write(1, str, len);
	ret += pf_post_pad(type, ret);
	free(str);
	return (ret);
}

static int	pf_put_ptr(t_pf_type type, va_list params)
{
	int	ptr;
	int	len;
	char	*str;
	char	*temp_str;

	if (!(str = ft_strnew(10)))
		return (0);
	ft_strcpy(str, "0x");
	ptr = va_arg(params, int);
	temp_str = NULL;
	if (!ptr)
		ft_strcpy(str + 2, "0");
	else if (!(temp_str = ft_itoa_base(ptr, 16, 1)))
		return (0);
	if (temp_str)
		ft_strcat_and_free(str, temp_str);
	len = ft_strlen(str);
	len += pf_pre_pad(type, len, 0);
	write(1, str, ft_strlen(str));
	pf_post_pad(type, len);
	free(str);
	return (len + 2);
}
/*
static pf_put_float(t_pf_type type, va_list params, char capitalise)
{
	long double	nb;
	long double	temp;
	int	len;
	char	str[1000];
	int		i;


	//divide by 10 until nb = 0;
	//put to string until last digit (i == 0)
	//get digits by multiplying by 10 (but how without %?)
	if (type.length == PRINTF_CPTL_L) {
		nb = va_arg(params, long double); printf("%Lf\n", nb); }
	else {
		nb = (long double)va_arg(params, double);printf("%f\n", (double)nb); }
	i = 0;
	if (nb < 0)
	{
		str[0] = '-';
		++i;
		nb = -nb;
	}	
	ft_bzero(str, 1000);
	temp = nb;
	len = 0;
	while (temp / 10.0 > 1.0)
	{
		temp /= 10.0;
		++len;
		//printf("%Lf", temp);
	}
	//printf("%Lf\n", nb);
	printf("len of integer part: %lu\n", len);
}
*/

static int	pf_float_to_str(t_pf_type type, long double dbl, char *str)
{
	unsigned long long	integer;
	unsigned long long	decimal;
	int				printed_len;

	integer = (unsigned long long)dbl;
	dbl = dbl - (long double)integer;
	decimal = (unsigned long long)
		(dbl * ft_intpow(10, (unsigned int)type.precision + 1));
	if (decimal % 10 > 4)
	{
		decimal += 10;
		if (!type.precision)
			++integer;
	}
	decimal /= 10;
	ft_strcat_and_free(str, ft_itoa(integer));
	printed_len = ft_strlen(str);
	if (type.precision)
	{
		str[printed_len++] = '.';
		str[printed_len] = 0;
		ft_strcat_and_free(str, ft_itoa(decimal));
	}
	return (ft_strlen(str));
}

static int	pf_put_float(t_pf_type type, va_list params, char capitalise)
{
	long double			dbl;
	char				str[50];
	int				printed_len;
	char				negative;

	ft_bzero(str, 50);
	type.precision = type.precision == -1 ? 6 : type.precision;
	if (type.length == PRINTF_CPTL_L)
		dbl = va_arg(params, long double);
	else
		dbl = (long double)va_arg(params, double);
	negative = dbl < 0 ? 1 : 0;
	if (negative)
	{
		type.sign = '-';
		dbl *= -1;
	}
	printed_len = pf_float_to_str(type, dbl, str + negative) + negative;
	pf_pre_pad(type, printed_len, 1);
	write(1, str, printed_len);
	pf_post_pad(type, printed_len);
	(void) capitalise; //added just to compile
	return (printed_len);
}

static int	pf_put_percent(t_pf_type type)
{
	int	printed_len;

	printed_len = pf_pre_pad(type, 1, 0);
	//printf("\nxd %% retval: %d\n", printed_len);
	printed_len += write(1, "%", 1);
//	printf("\nxd %% retval: %d\n", printed_len);
	printed_len += pf_post_pad(type, printed_len);
//	printf("\nxd %% retval: %d\n", printed_len);
	return (printed_len);
}

static int	pf_print_type(char c, t_pf_type type, va_list params)
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
	if (c == 'p')
		return (pf_put_ptr(type, params));
	if (c == 'f' || c == 'F')
		return (pf_put_float(type, params, c == 'F' ? 1 : 0));
	if (c == '%')
		return (pf_put_percent(type));
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
	int			len;
	//char	color;

	if (!(**str) || !*((*str)++)) //yooooo
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
	while (i < 4 && (type.flags[++i] = pf_is_flag(*str, &type)))
		++(*str);
	pf_get_width(str, &type);
	pf_get_precision(str, &type);
	pf_get_length(str, &type);
	len = pf_print_type(**str, type, params);
	**str ? ++(*str) : 0;
	return (len);
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
			//substr_len = pf_parse_format(&format, params);
			if ((substr_len = pf_parse_format(&format, params)) > 0)
				length += substr_len;
		}
	}
	va_end(params);
	return (length);
}
