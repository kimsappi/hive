/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksappi <ksappi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 15:47:23 by ksappi            #+#    #+#             */
/*   Updated: 2019/10/18 12:10:56 by ksappi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	if (!s)
		return (NULL);
	new = (char *)malloc(len + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (s[(size_t)start + i] && i < len)
	{
		new[i] = s[(size_t)start + i];
		++i;
	}
	new[i] = 0;
	return (new);
}
