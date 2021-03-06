/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_padding.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksappi <ksappi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 12:14:29 by ksappi            #+#    #+#             */
/*   Updated: 2020/02/03 09:08:41 by ksappi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_pre_pad(t_pf_type type, int len, char allow_flags)
{
	int		pad_len;
	char	pad_char;

	pad_char = ' ';
	if (pf_has_flag(type.flags, '-'))
	{
		if (type.sign)
			return (write(type.fd, &type.sign, 1));
		return (0);
	}
	if (pf_has_flag(type.flags, '0') && allow_flags)
	{
		pad_char = '0';
		if (!(type.precision < type.width && type.precision > -1))
			type.sign ? write(type.fd, &type.sign, 1) : 0;
	}
	if (type.precision < type.width && type.precision > -1)
		pad_char = ' ';
	pad_len = -1 + (type.sign / ' ') * allow_flags;
	while (++pad_len + len < (int)type.width && type.width > 0)
		write(type.fd, &pad_char, 1);
	if (type.sign && pad_char == ' ' && allow_flags)
		write(type.fd, &type.sign, 1);
	return (pad_len);
}

int	pf_pre_pad_uint_base(t_pf_type type, int len, char base, char capitalise)
{
	int		i;
	char	pad_char;
	int		printedlen;

	if (base == 16 && pf_has_flag(type.flags, '#'))
		ft_strcpy(type.uint_sign, capitalise ? "0X" : "0x");
	if (base == 8 && pf_has_flag(type.flags, '#'))
		ft_strcpy(type.uint_sign, "0");
	pad_char = ' ';
	printedlen = 0;
	if (pf_has_flag(type.flags, '-'))
		return (write(type.fd, type.uint_sign, ft_strlen(type.uint_sign)));
	if (pf_has_flag(type.flags, '0') && len)
	{
		pad_char = '0';
		printedlen = write(type.fd, type.uint_sign, ft_strlen(type.uint_sign));
	}
	if (type.precision < type.width && type.precision > -1)
		pad_char = ' ';
	i = -1 + ft_strlen(type.uint_sign);
	while (++i + len < (int)type.width && type.width > 0)
		printedlen += write(type.fd, &pad_char, 1);
	if (!(pf_has_flag(type.flags, '0')) && ft_strlen(type.uint_sign) && len)
		printedlen += write(type.fd, type.uint_sign, ft_strlen(type.uint_sign));
	return (printedlen);
}

int	pf_post_pad(t_pf_type type, int len)
{
	int		i;
	char	flag_found;

	i = -1;
	flag_found = pf_has_flag(type.flags, '-');
	if (!flag_found)
		return (0);
	i = -1;
	while (++i + len < (int)type.width && type.width > 0)
		write(type.fd, " ", 1);
	return (i);
}
