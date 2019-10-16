/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksappi <ksappi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:58:45 by ksappi            #+#    #+#             */
/*   Updated: 2019/10/16 17:40:58 by ksappi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

static char	*itoa_to_string(char *str, long nb, char length, char negative)
{
	char i;

	i = 1;
	str[length] = 0;
	if (negative)
		str[0] = '-';
	while (i + negative <= length)
	{
		str[length - i] = (char)(nb % 10) + '0';
		nb = nb / 10;
		++i;
	}
	return (str);
}

char		*ft_itoa(int n)
{
	long nb;
	char negative;
	char length;
	char *str;

	nb = (long)n;
	length = 0;
	while (n)
	{
		n = n / 10;
		++length;
	}
	negative = 0;
	if (nb < 0)
	{
		negative = 1;
		nb = -nb;
		++length;
	}
	if (!length)
		length = 1;
	str = (char *)malloc(length + 1);
	if (!str)
		return (NULL);
	return (itoa_to_string(str, nb, length, negative));
}
