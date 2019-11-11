/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksappi <ksappi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:05:34 by ksappi            #+#    #+#             */
/*   Updated: 2019/10/21 13:24:42 by ksappi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strtrim(char const *s)
{
	char	*new;
	size_t	sizes[3];

	if (!s)
		return (NULL);
	ft_bzero(sizes, 3 * sizeof(size_t));
	new = (char *)s;
	while (*new)
	{
		if (!sizes[1] && !sizes[2] && (*new == ' ' || *new == '\n' ||
			*new == '\t'))
			++sizes[0];
		else
		{
			++sizes[1];
			++sizes[2];
			if (!(*new == ' ' || *new == '\n' || *new == '\t'))
				sizes[2] = 0;
		}
		++new;
	}
	new = ft_strnew(sizes[1] - sizes[2]);
	if (new)
		ft_strncpy(new, s + sizes[0], sizes[1] - sizes[2]);
	return (new);
}
