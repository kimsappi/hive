/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksappi <ksappi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 11:33:52 by ksappi            #+#    #+#             */
/*   Updated: 2019/10/18 15:01:14 by ksappi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_length;
	size_t	src_length;

	dst_length = 0;
	src_length = 0;
	while (dst[dst_length] && dst_length < dstsize)
		++dst_length;
	while (src[src_length])
		++src_length;
	if (dst_length == dstsize)
		return (dstsize + src_length);
	if (src_length < dstsize - dst_length)
		ft_memcpy(dst + dst_length, src, src_length + 1);
	else
	{
		ft_memcpy(dst + dst_length, src, dstsize - dst_length - 1);
		dst[dstsize - 1] = 0;
	}
	return (dst_length + src_length);
}
