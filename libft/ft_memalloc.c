/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksappi <ksappi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 14:28:42 by ksappi            #+#    #+#             */
/*   Updated: 2019/10/18 12:09:38 by ksappi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*area;
	size_t	i;

	area = malloc(size);
	if (!area)
		return (NULL);
	i = 0;
	while (i < size)
	{
		area[i] = 0;
		++i;
	}
	return ((void *)area);
}
