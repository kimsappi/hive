/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksappi <ksappi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 12:44:33 by ksappi            #+#    #+#             */
/*   Updated: 2019/11/01 12:47:51 by ksappi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstappend(t_list **alst, t_list *new)
{
	t_list	*ptr;

	if (!new)
		return ;
	if (alst)
	{
		if (*alst)
		{
			new->next = *alst;
			*alst = new;
		}
		else
		{
			ptr = *alst;
			while (ptr->next)
				ptr = ptr->next;
			ptr->next = new;
		}
	}
}
