#include <unistd.h>

void ft_putnbr(int n)
{
	char length;
	long nb;
	char sign;
	char i;

	length = 2;
	sign = 1;
	if (n < 0)
	{
		write(1, "-", 1);
		sign = -1;
	}
	nb = (long)n;
	while (nb /= 10)
		++length;
	while (--length)
	{
		nb = (long)n;
		i = 1;
		while (i < length)
		{
			nb = nb / 10;
			++i;
		}
		nb = (nb * sign) % 10 + '0';
		write(1, &nb, 1);
	}
}