void	*ft_memcpy(void *str1, void *str2, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		(char *) str11[i] = (char *) str2[i];
		i++;
	}
	return (s1);
}

void	*ft_memccpy(void *str1, const void *str2, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		((char *) str1)[i] = ((char *) str2)[i];
		if (((char *) str2)[i] == (char) c)
			return (&((char *)str1)[++i]);
		++i;
	}
	return (NULL);
}

void	*ft_memset(void *str, int c, size_t n)
{
	while (n > 0)
	{
		((unsigned char *) str)[--n] = (unsigned char) c;
	}
	return (str);
}

void	*ft_bzero(void *s, size_t n)
{
	while (n > 0)
	{
		((char *) s)[--n] = 0;
	}
	return (s);
}

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		((char *) str1)[i] = ((char *) str2)[i];
		++i;
	}
	return (str1);
}

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *) str)[i] == (unsigned char) c)
			return (&((unsigned char *) str)[i]);
		++i;
	}
	return (NULL);
}

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t i;

	i = 0;
	while (((unsigned char *) str1)[i] == ((unsigned char *) str2)[i] &&
	i < n - 1)
		++i;
	return ((int) (((unsigned char *) str1)[i] - ((unsigned char *) str2)[i]));
}

char	*ft_strcat(char *dest, const char *src)
{
	char *dest_ptr;
	char *src_ptr;

	dest_ptr = dest;
	src_ptr = (char *) src;
	while (*dest_ptr)
		++dest_ptr;
	while (*src_ptr)
	{
		*dest_ptr = *src_ptr;
		++dest_ptr;
		++src_ptr;
	}
	*dest_ptr = 0;
	return (dest);
}

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char	*dest_ptr;
	char	*src_ptr;
	size_t	i;

	i = 0;
	dest_ptr = dest;
	src_ptr = (char *) src;
	while (*dest_ptr)
		++dest_ptr;
	while (*src_ptr && i++ < n)
	{
		*dest_ptr = *src_ptr;
		++dest_ptr;
		++src_ptr;
	}
	*dest_ptr = 0;
	return (dest);
}

