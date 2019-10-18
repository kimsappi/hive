/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksappi <ksappi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 11:06:54 by ksappi            #+#    #+#             */
/*   Updated: 2019/10/18 14:11:34 by ksappi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *str1, const void *str2, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		((char *)str1)[i] = ((char *)str2)[i];
		if (((char *)str2)[i] == (char)c)
			return (&((char *)str1)[++i]);
		++i;
	}
	return (NULL);
}
