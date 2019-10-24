#include "libft.h"

size_t	ft_strclen(const char *s, int c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		++len;
	if (s[len] != c)
		--len;
	return (len);
}
