/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksappi <ksappi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 10:35:56 by ksappi            #+#    #+#             */
/*   Updated: 2019/10/18 12:10:08 by ksappi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	char length;
	long nb;
	char sign;
	char i;

	length = 2;
	sign = 1;
	if (n < 0)
	{
		write(1, "-", 1);
		sign = -1;
	}
	nb = (long)n;
	while (nb /= 10)
		++length;
	while (--length)
	{
		nb = (long)n;
		i = 0;
		while (++i < length)
			nb = nb / 10;
		nb = (nb * sign) % 10 + '0';
		write(1, &nb, 1);
	}
}
