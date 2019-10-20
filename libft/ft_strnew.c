/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksappi <ksappi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 14:41:14 by ksappi            #+#    #+#             */
/*   Updated: 2019/10/18 12:10:47 by ksappi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*area;
	size_t	i;

	area = (char *)malloc(sizeof(char) * (size + 1));
	if (!area)
		return (NULL);
	i = 0;
	while (i < size + 1)
	{
		area[i] = '\0';
		++i;
	}
	return (area);
}
