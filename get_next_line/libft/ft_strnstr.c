/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksappi <ksappi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:05:36 by ksappi            #+#    #+#             */
/*   Updated: 2019/10/18 12:10:48 by ksappi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	length;
	size_t	i;
	char	*ptr;

	if (needle[0] == 0)
		return ((char *)haystack);
	ptr = (char *)haystack;
	length = 0;
	i = 0;
	while (needle[length++] && len > 0)
		--len;
	while (i <= len)
	{
		if (*ptr == needle[0])
		{
			length = 0;
			while (needle[length] && needle[length] == ptr[length])
				++length;
			if (!needle[length])
				return (ptr);
		}
		++i;
		++ptr;
	}
	return (NULL);
}
