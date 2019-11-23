/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksappi <ksappi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 12:08:36 by ksappi            #+#    #+#             */
/*   Updated: 2019/11/23 13:34:20 by ksappi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Returns string with result of base conversion nb(decimal) to nb(base)
*/

#include "libft.h"

char	*ft_itoa_base(unsigned long long nb, char base, char capitalise)
{
	char				*str;
	char				digits[16];
	int					len;
	unsigned long long	nb_copy;

	nb_copy = nb;
	len = 0;
	while ((nb_copy /= base) > 0)
		++len;
	if (base < 2 || base > 16 || !(str = ft_strnew(len + 1)))
		return (NULL);
	if (capitalise)
		ft_memcpy(digits, "0123456789ABCDEF", 16 * sizeof(char));
	else
		ft_memcpy(digits, "0123456789abcdef", 16 * sizeof(char));
	while (len > -1)
	{
		str[len] = digits[nb % base];
		nb /= base;
		--len;
	}
	return (str);
}
