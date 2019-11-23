/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksappi <ksappi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 13:14:23 by ksappi            #+#    #+#             */
/*   Updated: 2019/11/23 12:35:54 by ksappi           ###   ########.fr       */
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
	char	sign;
	char	uint_sign[3];
}				t_pf_type;

int		ft_printf(const char *format, ...);
char	pf_has_flag(char *flags, char flag);
char	pf_is_flag(const char *str, t_pf_type *type);
void	pf_type_init(t_pf_type *type);
void	pf_get_width(const char **str, t_pf_type *type);
void	pf_get_length(const char **str, t_pf_type *type);
void	pf_get_precision(const char **str, t_pf_type *type);
int		pf_pre_pad(t_pf_type type, int len, char allow_flags);
int		pf_pre_pad_uint_base(t_pf_type type, int len, char base, char capitalise);
int		pf_post_pad(t_pf_type type, int len);
int		pf_put_float(t_pf_type type, va_list params);
int		pf_put_int(t_pf_type type, va_list params);
int		pf_put_uint_base(t_pf_type type, va_list params, char base, char capitalise);
int		pf_put_char(t_pf_type type, va_list params);
int		pf_put_str(t_pf_type type, va_list params);
int		pf_put_ptr(t_pf_type type, va_list params);
int		pf_put_percent(t_pf_type type);

#endif
