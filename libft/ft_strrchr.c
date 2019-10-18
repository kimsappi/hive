/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksappi <ksappi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 12:55:08 by ksappi            #+#    #+#             */
/*   Updated: 2019/10/18 12:10:49 by ksappi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *ptr;
	char *last_occurrence;

	last_occurrence = NULL;
	ptr = (char *)s;
	while (*ptr)
	{
		if (*ptr == (char)c)
			last_occurrence = ptr;
		++ptr;
	}
	return (last_occurrence);
}
