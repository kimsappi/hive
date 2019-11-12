/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksappi <ksappi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 13:14:23 by ksappi            #+#    #+#             */
/*   Updated: 2019/11/12 11:11:52 by ksappi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//probably need to add this to libft?

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>

# define PRINTF_HH 1
# define PRINTF_H 2
# define PRINTF_LL 3
# define PRINTF_L 4
# define PRINTF_CPTL_L 5

# define PF_CHAR 1
# define PF_STR 2
# define PF_PTR 3
# define PF_INT 4
# define PF_UINT 5

typedef struct	s_pf_type
{
//	int		parameter;
	char	flags[6];
	int		width;
	int		precision;
	char	length;
	char	type;
}				t_pf_type;

int	ft_printf(const char *format, ...);

#endif
