/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksappi <ksappi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 11:14:19 by ksappi            #+#    #+#             */
/*   Updated: 2019/10/18 12:10:40 by ksappi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char	*dest_ptr;
	char	*src_ptr;
	size_t	i;

	i = 0;
	dest_ptr = dest;
	src_ptr = (char *)src;
	while (*dest_ptr)
		++dest_ptr;
	while (*src_ptr && i++ < n)
	{
		*dest_ptr = *src_ptr;
		++dest_ptr;
		++src_ptr;
	}
	*dest_ptr = 0;
	return (dest);
}
