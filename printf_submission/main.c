#include "ft_printf.h"
#include <stdio.h>

int main() {
double d = 123.45678901234;
	
	/*	int ret = -1;
	char a[] = "asd";
ft_printf("##########asd\n%s\n%c\n", "123", 'X');
ft_printf("%-05da\n", 123);
ft_printf("next line should be hex:\n");
ft_printf("%x\n", 200);
ft_printf("ptr: %p\n", a);
ft_printf("nullptr: %p\n", NULL);
printf("###################\n");

printf("real\nft\n");
printf("%05d\n", 123);
ft_printf("%05d\n", 123);
ret = ft_printf("%5%\n");
printf("ret: %d\n", ret);
ret = ft_printf("%08x\n", 42);
printf("ret: %d\n", ret);

ft_printf("%05.3d\n", -42);
printf("%05.3d\n", -42);
*/

printf("%p\n%7pa\n", NULL, NULL);
ft_printf("%p\n%7pa\n", NULL, NULL);
ft_printf("undefined:\n");
ft_printf("% h\n");
printf("%.3s\n", NULL);
ft_printf("%.3s\n", NULL);
printf("#%08.5x#\n", 0);
ft_printf("#%08.5x#\n", 0);
printf("#%#-3x#\n", 0);
ft_printf("#%#-3x#\n", 0);

ft_printf("\n###\n%.10f\n", d);
printf("%.10f\n###\n", d);

ft_printf("%p\n", &ft_printf);
printf("%p\n", &ft_printf);

printf("------------\n");
d = 0.999999;
ft_printf("%f\n", d);
printf("%f\n", d);
printf("------------\n");
d = 0.9999999;
ft_printf("%f\n", d);
printf("%f\n", d);
printf("------------\n");

ft_printf("%.3s\n", "hello");
printf("%.3s\n", "hello");

return 0;
}
