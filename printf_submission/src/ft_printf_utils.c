/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksappi <ksappi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 12:11:07 by ksappi            #+#    #+#             */
/*   Updated: 2019/11/26 17:06:47 by ksappi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	pf_has_flag(char *flags, char flag)
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

char	pf_is_flag(const char *str, t_pf_type *type)
{
	char	ret;

	ret = 0;
	if (*str == '+' || *str == ' ')
	{
		if (!(*str == ' ' && type->sign))
			type->sign = *str;
		return (*str);
	}
	if (*str == ' ' || *str == '#' || *str == '0' || *str == '-' || *str == '+')
		ret = 1;
	if (ret)
	{
		if (*str == ' ')
			type->flags[0] = *str;
		else if (*str == '#')
			type->flags[1] = *str;
		else if (*str == '0')
			type->flags[2] = *str;
		else if (*str == '-')
			type->flags[3] = *str;
		else
			type->flags[4] = *str;
	}
	return (ret);
}

void	pf_type_init(t_pf_type *type, int fd)
{
	type->type = 0;
	ft_bzero(type->flags, 6 * sizeof(char));
	ft_bzero(type->uint_sign, 3 * sizeof(char));
	type->precision = -1;
	type->width = -1;
	type->length = -1;
	type->sign = 0;
	type->fd = fd;
}
