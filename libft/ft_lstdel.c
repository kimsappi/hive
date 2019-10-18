/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksappi <ksappi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 10:42:13 by ksappi            #+#    #+#             */
/*   Updated: 2019/10/18 12:09:23 by ksappi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*next;
	t_list	*current;

	if (alst)
	{
		current = *alst;
		while (current)
		{
			next = current->next;
			(*del)(current->content, current->content_size);
			free(current);
			current = next;
		}
		*alst = NULL;
	}
}
