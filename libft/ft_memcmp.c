/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksappi <ksappi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 11:11:54 by ksappi            #+#    #+#             */
/*   Updated: 2019/10/18 12:09:44 by ksappi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t i;

	if (!n)
		return (0);
	i = 0;
	while (((unsigned char *)str1)[i] == ((unsigned char *)str2)[i] &&
	i < n - 1)
		++i;
	return ((int)(((unsigned char *)str1)[i] - ((unsigned char *)str2)[i]));
}
