/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_text.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksappi <ksappi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 12:20:37 by ksappi            #+#    #+#             */
/*   Updated: 2019/11/26 17:06:09 by ksappi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_put_char(t_pf_type type, va_list params)
{
	int c;
	int printed_len;

	c = va_arg(params, int);
	printed_len = pf_pre_pad(type, 1, 0);
	printed_len += write(1, &c, 1);
	printed_len += pf_post_pad(type, printed_len);
	return (printed_len);
}

int	pf_put_str(t_pf_type type, va_list params)
{
	char	*str;
	int		len;
	int		printed_len;
	char	null_str[7];

	str = va_arg(params, char*);
	if (!str)
	{
		ft_strcpy(null_str, "(null)");
		str = null_str;
	}
	len = ft_strlen(str);
	if (type.precision != -1 && type.precision < len)
		len = type.precision;
	printed_len = pf_pre_pad(type, len, 0);
	printed_len += write(1, str, len);
	printed_len += pf_post_pad(type, printed_len);
	return (printed_len);
}

int	pf_put_ptr(t_pf_type type, va_list params)
{
	unsigned long	ptr;
	int				len;
	char			*str;
	char			*temp_str;

	if (!(str = ft_strnew(19)))
		return (0);
	ft_strcpy(str, "0x");
	ptr = va_arg(params, unsigned long);
	temp_str = NULL;
	if (!ptr)
		ft_strcpy(str + 2, "0");
	else if (!(temp_str = ft_itoa_base((unsigned long long)ptr, 16, 0)))
		return (0);
	if (temp_str)
	{
		ft_strlen(temp_str) < 8 ? ft_strcat(str, "10") : 0;
		ft_strcat_and_free(str, temp_str);
	}
	len = ft_strlen(str);
	len += pf_pre_pad(type, len, 0);
	write(1, str, ft_strlen(str));
	pf_post_pad(type, len);
	free(str);
	return (len);
}

int	pf_put_percent(t_pf_type type)
{
	int	printed_len;

	printed_len = pf_pre_pad(type, 1, 0);
	printed_len += write(1, "%", 1);
	printed_len += pf_post_pad(type, printed_len);
	return (printed_len);
}
