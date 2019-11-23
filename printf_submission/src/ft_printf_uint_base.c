/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uint_base.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksappi <ksappi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 12:26:15 by ksappi            #+#    #+#             */
/*   Updated: 2019/11/23 13:41:01 by ksappi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

static char					*pf_uint_to_string
	(t_pf_type type, unsigned long long nb, char base, char capitalise)
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
		}
		free(str);
	}
	return (str_padded);
}

int							pf_put_uint_base
	(t_pf_type type, va_list params, char base, char capitalise)
{
	char				*str;
	unsigned long long	nb;
	int					len;
	int					ret;

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
