/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_get_style.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksappi <ksappi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 12:12:41 by ksappi            #+#    #+#             */
/*   Updated: 2020/02/03 10:22:33 by ksappi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_get_width(const char **str, t_pf_type *type)
{
	if (ft_isdigit(**str))
	{
		type->width = ft_atoi(*str);
		while (ft_isdigit(**str))
			++(*str);
	}
}

void	pf_get_length(const char **str, t_pf_type *type)
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
}

void	pf_get_precision(const char **str, t_pf_type *type)
{
	if (**str == '.')
	{
		++(*str);
		if (**str)
		{
			type->precision = ft_atoi(*str);
			while (ft_isdigit(**str))
				++(*str);
		}
	}
}
