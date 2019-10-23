/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksappi <ksappi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 12:00:55 by ksappi            #+#    #+#             */
/*   Updated: 2019/10/21 13:45:50 by ksappi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_get_array_for_words(char const *s, char c)
{
	size_t	word_count;
	char	start_new_word;

	start_new_word = 1;
	word_count = 0;
	while (*s)
	{
		if ((char)(*s) == c)
			start_new_word = 1;
		else
		{
			if (start_new_word)
			{
				++word_count;
				start_new_word = 0;
			}
		}
		++s;
	}
	return ((char **)malloc(sizeof(char *) * (word_count + 1)));
}

static char	*ft_split_word_length(char const *s, char c)
{
	size_t	length;
	char	*word;

	length = 0;
	while (((char *)s)[length] && ((char *)s)[length] != c)
		++length;
	word = ft_strnew(length);
	if (!word)
		return (NULL);
	word = ft_strncpy(word, s, length);
	return (word);
}

static char	**ft_free_split(char **split)
{
	if (split)
	{
		while (*split)
		{
			free(split);
			++split;
		}
	}
	return (NULL);
}

char		**ft_strsplit(char const *s, char c)
{
	size_t	i;
	char	**arr;

	if (!s || !(arr = ft_get_array_for_words(s, c)))
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s == c)
			;
		else if (!(arr[i] = ft_split_word_length(s, c)))
		{
			ft_free_split(arr);
			return (NULL);
		}
		else
		{
			s += ft_strlen(arr[i]) - 1;
			++i;
		}
		++s;
	}
	arr[i] = NULL;
	return (arr);
}
