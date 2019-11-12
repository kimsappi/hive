#include "ft_printf.h"

int main() {
ft_printf("##########asd\n%s\n%c\n", "123", 'X');
ft_printf("%-05da\n", 123);
ft_printf("next line should be hex:\n");
ft_printf("%o\n", 200);
return 0;
}
