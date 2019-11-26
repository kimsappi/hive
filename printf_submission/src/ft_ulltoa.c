/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksappi <ksappi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:58:45 by ksappi            #+#    #+#             */
/*   Updated: 2019/11/26 15:03:52 by ksappi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ulltoa_to_string (char *str, unsigned long long nb, char length)
{
	char i;

	if (!str)
		return (NULL);
	i = 1;
	str[(int)length] = 0;
	while (i <= length)
	{
		str[length - i] = (char)(nb % 10) + '0';
		nb = nb / 10;
		++i;
	}
	return (str);
}

char		*ft_ulltoa(unsigned long long n)
{
	long long	nb;
	char		length;
	char		*str;

	nb = n;
	length = 0;
	while (n)
	{
		n = n / 10;
		++length;
	}
	if (!length)
		length = 1;
	str = (char *)malloc(length + 1);
	return (ulltoa_to_string(str, nb, length));
}
