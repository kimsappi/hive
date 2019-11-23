/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_float.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksappi <ksappi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 12:19:18 by ksappi            #+#    #+#             */
/*   Updated: 2019/11/23 13:35:24 by ksappi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	pf_float_to_str(t_pf_type type, long double dbl, char *str)
{
	unsigned long long	integer;
	unsigned long long	decimal;
	int					printed_len;

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

int			pf_put_float(t_pf_type type, va_list params)
{
	long double		dbl;
	char			str[50];
	int				printed_len;
	char			negative;

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
	return (printed_len);
}
