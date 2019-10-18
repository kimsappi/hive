/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksappi <ksappi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 23:06:40 by ksappi            #+#    #+#             */
/*   Updated: 2019/10/18 12:10:52 by ksappi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_words(char const *str, char c)
{
	size_t	words;
	size_t	i;

	words = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			if (i > 0)
			{
				if (str[i - 1] == c)
					words++;
			}
			else
				words = 1;
		}
		i++;
	}
	return (words);
}

static size_t	*count_word_sizes(size_t word_count, char const *str, char c)
{
	size_t	*word_sizes;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	word_sizes = malloc(sizeof(size_t) * (word_count));
	if (!word_sizes)
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			if (i > 0)
			{
				if (str[i - 1] == c && word_sizes[j] > 0)
					j++;
			}
			word_sizes[j]++;
			if (j == word_count)
				break ;
		}
		i++;
	}
	return (word_sizes);
}

static size_t	write_word(size_t size, char const *str, char *word, char c)
{
	size_t	i;
	size_t	forward;

	forward = 0;
	i = 0;
	while (i < size)
	{
		if (str[forward] != c)
		{
			word[i] = str[forward];
			i++;
		}
		forward++;
	}
	word[i] = '\0';
	return (forward);
}

static void		ft_free_split(char **array, size_t count)
{
	size_t	i;

	i = 0;
	while (i <= count)
	{
		free(array[i]);
		++i;
	}
	free(array);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**array;
	size_t	word_count;
	size_t	i;
	size_t	*word_sizes;

	i = -1;
	word_count = count_words(s, c);
	array = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!array)
		return (NULL);
	word_sizes = count_word_sizes(word_count, s, c);
	while (++i < word_count && word_sizes)
	{
		array[i] = (char *)malloc(sizeof(char) * (word_sizes[i] + 1));
		if (!array[i])
		{
			ft_free_split(array, i - 1);
			return (NULL);
		}
		s = s + write_word(word_sizes[i], s, array[i], c);
	}
	array[word_count] = NULL;
	if (!word_sizes)
		array[0] = NULL;
	return (array);
}
