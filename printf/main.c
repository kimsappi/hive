#include "ft_printf.h"

#include <stdio.h>

int main()
{
    long double a = -12345.12345678901234;
    double b = (double)a;
    float c = (float)a;
	   printf("real: %20.10Lf\n", a);
	ft_printf("ft  : %20.10Lf\n", a);
	   printf("real: %20.10f\n", b);
	ft_printf("ft  : %20.10f\n", b);
	   printf("real: %20.10f\n", c);
	ft_printf("ft  : %20.10f\n", c);

	while(1);
    return 0;
}
