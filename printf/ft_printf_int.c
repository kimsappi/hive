/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksappi <ksappi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 12:25:27 by ksappi            #+#    #+#             */
/*   Updated: 2019/11/23 12:26:47 by ksappi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

static char			*pf_int_to_string(t_pf_type type, long long nb)
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
		}
		if (str_padded && negative)
			str_padded[0] = '-';
		free(str);
	}
	return (str_padded);
}

int					pf_put_int(t_pf_type type, va_list params)
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
	if (!type.precision && !nb)
	{
		len = 0;
		str[0] = 0;
	}
	printed_len = len;
	negative = str[0] == '-' ? 1 : 0;
	negative ? type.sign = '-' : 0;
	printed_len += pf_pre_pad(type, len - negative, 1);
	write(1, str + negative, len - negative);
	printed_len += pf_post_pad(type, printed_len - negative);
	free(str);
	return (printed_len - negative);
}