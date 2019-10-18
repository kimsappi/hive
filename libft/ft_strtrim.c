/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksappi <ksappi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:05:34 by ksappi            #+#    #+#             */
/*   Updated: 2019/10/18 12:31:57 by ksappi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	end;
	size_t	body;
	char	*new;

	start = 0;
	end = 0;
	body = 0;
	new = (char *)s;
	while (*new)
	{
		if (!body && !end && (*new == ' ' || *new == '\n' || *new == '\t'))
			++start;
		else
		{
			++body;
			++end;
			if (!(*new == ' ' || *new == '\n' || *new == '\t'))
				end = 0;
		}
	}
	new = ft_strnew(body - end);
	if (new)
		ft_strncpy(new, s + start, body - end);
	return (new);
}
