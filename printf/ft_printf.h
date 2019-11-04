/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksappi <ksappi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 13:14:23 by ksappi            #+#    #+#             */
/*   Updated: 2019/11/04 11:00:46 by ksappi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//probably need to add this to libft?

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"

# define PF_HH 2
# define PF_H 1
# define PF_LL 12
# define PF_L 11
# define PF_CPTL_L 21
# define PF_HASH 31
# define PF_ZERO 41
# define PF_MINUS 51
# define PF_PLUS 61
# define PF_SPACE 71

# define PF_CHAR 1
# define PF_STR 2
# define PF_PTR 3
# define PF_INT 4
# define PF_UINT 5

# define PF_MAX_FLAGS 10

typedef struct	s_pf_type
{
	char	type;
	char	flags[PF_MAX_FLAGS];
	int		precision;
	int		width;
	int		parameter;
}				t_pf_type;


int	ft_printf(const char *format, ...);

#endif
