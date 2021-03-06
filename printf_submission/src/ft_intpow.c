/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intpow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksappi <ksappi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 15:13:25 by ksappi            #+#    #+#             */
/*   Updated: 2019/10/22 12:31:55 by ksappi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long	ft_intpow(int base, unsigned int exponent)
{
	unsigned long long	result;
	unsigned int		i;

	if (!exponent)
		return (base >= 0 ? 1 : -1);
	i = 1;
	result = (unsigned long long)base;
	while (i < exponent)
	{
		result *= (unsigned long long)base;
		++i;
	}
	return (result);
}
