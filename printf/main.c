#include "ft_printf.h"
#include <stdio.h>

int main() {
	int ret = -1;
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
printf("%d", ret);

return 0;
}
