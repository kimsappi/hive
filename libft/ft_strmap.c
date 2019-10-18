/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksappi <ksappi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 15:23:35 by ksappi            #+#    #+#             */
/*   Updated: 2019/10/18 12:10:37 by ksappi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	unsigned long	len;
	unsigned long	i;
	char			*new;

	if (!s || !f)
		return (NULL);
	len = 0;
	while (s[len])
		++len;
	new = (char *)malloc(len + 1);
	if (!new)
		return (0);
	i = 0;
	while (i < len)
	{
		new[i] = (*f)(s[i]);
		++i;
	}
	new[len] = 0;
	return (new);
}
