#include "ft_printf.h"

int main() {
	char a[] = "asd";
ft_printf("##########asd\n%s\n%c\n", "123", 'X');
ft_printf("%-05da\n", 123);
ft_printf("next line should be hex:\n");
ft_printf("%x\n", 200);
ft_printf("ptr: %p\n", a);
ft_printf("nullptr: %p\n", NULL);
return 0;
}
