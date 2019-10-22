/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksappi <ksappi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 14:58:46 by ksappi            #+#    #+#             */
/*   Updated: 2019/10/21 15:27:41 by ksappi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(void *src, size_t size)
{
	void	*dst;
	size_t	i;

	if (!src || !size)
		return (NULL);
	dst = (void *)malloc(size);
	if (!dst)
		return (NULL);
	i = 0;
	while (i < size)
	{
		((char *)dst)[i] = ((char *)src)[i];
		++i;
	}
	return (dst);
}
