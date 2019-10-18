/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksappi <ksappi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 14:00:34 by ksappi            #+#    #+#             */
/*   Updated: 2019/10/18 12:14:18 by ksappi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int sign;
	int result;
	int is_number;

	sign = 1;
	result = 0;
	is_number = 0;
	while (*str && !(is_number && !ft_isdigit(*str)))
	{
		if (*str > 32 && *str != '-' && *str != '+' && !ft_isdigit(*str))
			break ;
		if (*str == '-')
			sign = -1;
		if (ft_isdigit(*str))
			result = result * 10 + (*str - '0');
		if (*str > 32)
			is_number = 1;
		str++;
	}
	return (result * sign);
}
