/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ceil_sqrt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksappi <ksappi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 14:09:57 by ksappi            #+#    #+#             */
/*   Updated: 2019/11/01 10:38:41 by ksappi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns Math.ceil(Math.sqrt(n))
*/

int	ft_ceil_sqrt(unsigned int n)
{
	unsigned int	sqrt;

	sqrt = 0;
	while (sqrt * sqrt < n)
	{
		if (sqrt > 65535)
			return (-1);
		++sqrt;
	}
	return (sqrt);
}
