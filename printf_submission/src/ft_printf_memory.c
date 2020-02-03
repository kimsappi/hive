#include "ft_printf.h"
#include <stdio.h>

static int	pf_put_memory_byte(t_pf_type type, unsigned char c, int capitalise)
{
	char	*format_string;
	int		length;

	length = 0;
	if (type.precision == 2)
		format_string = ft_strdup("%08b");
	else if (type.precision == 8)
		format_string = ft_strdup("%03o");
	else if (capitalise)
		format_string = ft_strdup("%02X");
	else
		format_string = ft_strdup("%02x");
	if (format_string) {
		length = ft_printf_fd(type.fd, format_string, (unsigned int)c);
		free(format_string);
	}
	return (length);
}

int pf_put_memory_bytes(t_pf_type type, va_list params, int capitalise)
{
	unsigned char	*ptr;
	int				i;
	int				printed_len;

	if (type.precision != 2 && type.precision != 8 && type.precision != 16)
		return (0);
	ptr = va_arg(params, unsigned char *);
	printed_len = 0;
	i = -1;
	while (++i < type.width)
	{
		if (i > 0)
			printed_len += write(type.fd, " ", 1);
		printed_len += pf_put_memory_byte(type, *(ptr + i), capitalise);
	}
	return (printed_len);
}