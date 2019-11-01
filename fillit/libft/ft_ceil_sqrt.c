/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ceil_sqrt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksappi <ksappi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 14:09:57 by ksappi            #+#    #+#             */
/*   Updated: 2019/11/01 13:13:12 by ksappi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns Math.ceil(Math.sqrt(n))
*/

int	ft_ceil_sqrt(unsigned int n)
{
	unsigned int	sqrt;

	if (n > 4294836225)
	return (65536);
	sqrt = 0;
	while (sqrt * sqrt < n)
	{
		if (sqrt > 65537)
			return (-1);
		++sqrt;
	}
	return ((int)sqrt);
}