void *ft_memcpy(void *str1, void *str2, size_t n)
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

void *ft_memccpy(void *str1, const void *str2, int c, size_t n)
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

void *ft_memset(void *str, int c, size_t n)
{
	while (n > 0)
	{
		((unsigned char *) str)[--n] = (unsigned char) c;
	}
	return (str);
}