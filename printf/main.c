#include "ft_printf.h"
#include <stdio.h>

int main() {
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

return 0;
}
