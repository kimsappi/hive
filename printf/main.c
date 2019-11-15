#include "ft_printf.h"

#include <stdio.h>

int main()
{
    long double a = 12345.12345678901234;
    double b = (double)a;
    float c = (float)a;
	printf("real: %Lf\n", a);
	ft_printf("ft  : %Lf\n", a);
	printf("real: %f\n", b);
	ft_printf("ft  : %f\n", b);
	printf("real: %f\n", c);
	ft_printf("ft  : %f\n", c);

    return 0;
}
