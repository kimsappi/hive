/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksappi <ksappi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 15:33:17 by ksappi            #+#    #+#             */
/*   Updated: 2019/10/18 12:10:39 by ksappi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned long	len;
	unsigned long	i;
	char			*new;

	len = 0;
	while (s[len])
		++len;
	new = (char *)malloc(len + 1);
	if (!new)
		return (0);
	i = 0;
	while (i < len)
	{
		new[i] = (*f)(i, s[i]);
		++i;
	}
	new[len] = 0;
	return (new);
}
