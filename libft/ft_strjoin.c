/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksappi <ksappi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 15:59:30 by ksappi            #+#    #+#             */
/*   Updated: 2019/10/18 12:17:55 by ksappi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned long	len1;
	unsigned long	len2;
	unsigned long	i;
	char			*new;

	len1 = 0;
	len2 = 0;
	while (s1[len1])
		++len1;
	while (s2[len2])
		++len2;
	new = (char *)malloc(len1 + len2 + 1);
	i = 0;
	while (i < len1)
	{
		new[i] = s1[i];
		++i;
	}
	while (i < len1 + len2)
	{
		new[i] = s2[i - len1];
		++i;
	}
	new[i] = 0;
	return (new);
}
