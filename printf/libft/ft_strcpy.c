/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksappi <ksappi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 17:08:13 by ksappi            #+#    #+#             */
/*   Updated: 2019/10/18 12:10:22 by ksappi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	size_t length;
	size_t i;

	length = 0;
	i = 0;
	while (src[length++])
		;
	while (i < length)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}
