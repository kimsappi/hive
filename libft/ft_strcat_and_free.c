/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat_and_free.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksappi <ksappi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 12:07:13 by ksappi            #+#    #+#             */
/*   Updated: 2019/11/23 12:07:19 by ksappi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_strcat_and_free(char *s1, char *s2)
{
	if (!s2 || !s1)
		return (0);
	else
	{
		ft_strcat(s1, s2);
		free(s2);
		return (1);
	}
}
