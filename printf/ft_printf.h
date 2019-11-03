/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksappi <ksappi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 13:14:23 by ksappi            #+#    #+#             */
/*   Updated: 2019/11/03 13:38:18 by ksappi           ###   ########.fr       */
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

int	ft_printf(const char *format, ...);

#endif
