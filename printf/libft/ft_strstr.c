/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksappi <ksappi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 17:26:53 by ksappi            #+#    #+#             */
/*   Updated: 2019/10/18 12:10:53 by ksappi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t i;
	size_t j;

	if (!needle[0])
		return (char*)(haystack);
	i = -1;
	while (haystack[++i])
	{
		if (needle[0] == haystack[i])
		{
			j = 0;
			while (needle[j] == haystack[i + j])
			{
				j++;
				if (!needle[j])
					return (char*)(&haystack[i]);
			}
		}
	}
	return (NULL);
}
