/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksappi <ksappi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 12:11:07 by ksappi            #+#    #+#             */
/*   Updated: 2019/11/23 12:11:29 by ksappi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	pf_has_flag(char *flags, char flag)
{
	int	i;

	i = -1;
	while (++i < 6)
	{
		if (flags[i] == flag)
			return (1);
	}
	return (0);
}

char	pf_is_flag(const char *str, t_pf_type *type)
{
	if (*str == '+' || *str == ' ')
	{
		if (!(*str == ' ' && type->sign))
			type->sign = *str;
		return (*str);
	}
	if (*str == ' ' || *str == '#' || *str == '0' || *str == '-' || *str == '+')
		return (*str);
	return (0);
}

void	pf_type_init(t_pf_type *type)
{
	type->type = 0;
	ft_bzero(type->flags, 6 * sizeof(char));
	ft_bzero(type->uint_sign, 3 * sizeof(char));
	type->precision = -1;
	type->width = -1;
	type->length = -1;
	type->sign = 0;
}
