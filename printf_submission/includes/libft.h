/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksappi <ksappi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 10:44:38 by ksappi            #+#    #+#             */
/*   Updated: 2019/11/23 13:48:59 by ksappi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>

# define BUFF_SIZE 100
# define MAX_BUFF 7900000
# define MAX_FD 4863

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strchr(const char *s, int c);
int				ft_atoi(const char *str);
int				ft_isdigit(int c);
char			*ft_strnew(size_t size);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_itoa(int n);
long			ft_intpow(int base, unsigned int exponent);
size_t			ft_strclen(char const *s, int c);
char			*ft_lltoa(long long n);
char			ft_strcat_and_free(char *s1, char *s2);
char			*ft_itoa_base
					(unsigned long long nb, char base, char capitalise);

#endif
