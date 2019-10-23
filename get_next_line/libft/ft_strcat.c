/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksappi <ksappi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 11:12:55 by ksappi            #+#    #+#             */
/*   Updated: 2019/10/18 12:10:17 by ksappi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	char *dest_ptr;
	char *src_ptr;

	dest_ptr = dest;
	src_ptr = (char *)src;
	while (*dest_ptr)
		++dest_ptr;
	while (*src_ptr)
	{
		*dest_ptr = *src_ptr;
		++dest_ptr;
		++src_ptr;
	}
	*dest_ptr = 0;
	return (dest);
}
