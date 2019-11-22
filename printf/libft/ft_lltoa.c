/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksappi <ksappi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:58:45 by ksappi            #+#    #+#             */
/*   Updated: 2019/10/18 12:09:17 by ksappi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*lltoa_to_string(char *str, long long nb, char length, char negative)
{
	char i;

	if (!str)
		return (NULL);
	i = 1;
	str[(int)length] = 0;
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

char		*ft_lltoa(long long n)
{
	long long	nb;
	char		negative;
	char		length;
	char		*str;

	if (n == -9223372036854775807)
		return (ft_strdup("-9223372036854775807"));
	nb = n;
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
	return (lltoa_to_string(str, nb, length, negative));
}
