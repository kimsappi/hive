/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksappi <ksappi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 15:57:13 by ksappi            #+#    #+#             */
/*   Updated: 2019/11/01 18:10:40 by ksappi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ft_convert has to return length of conversion written and point **str to
// first char after conversion
static size_t	ft_convert(char **str)
{
	
}

int	ft_printf(const char *format, ...)
{
	t_list	*head;
	t_list	*current;
	int		substr_len;
	int		length;

	written = 0;
	head = NULL;
	if (format)
	{
		while (substr_len = ft_strclen(format, '%'))
		{
			length += substr_len;
			write(1, format, substr_len);
			format += substr_len;
			if (!(substr_len = ft_convert(&format)))
				return (length);
			length += substr_len;
		}
	}
	return (length);
}
