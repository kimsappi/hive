#include <stdio.h>
#include <fcntl.h>

int main() {
double d = 123.45678901234;
int ret1;
int ret2;
	char a[] = "asd";
ret1 = ft_printf("##########asd\n%s\n%c\n", "123", 'X');
ret2 = printf("##########asd\n%s\n%c\n", "123", 'X');
ret1 != ret2 ? printf("\n\n\n\nERROR\nft: %d\nrl: %d\n\n", ret1, ret2) : 0; printf("\n\n");

ret1 = ft_printf("%-05da\n", 123);
ret2 = printf("%-05da\n", 123);
ret1 != ret2 ? printf("\n\n\n\nERROR\nft: %d\nrl: %d\n\n", ret1, ret2) : 0; printf("\n\n");

ret1 = ft_printf("next line should be hex:\n");
ret2 = printf("next line should be hex:\n");
ret1 != ret2 ? printf("\n\n\n\nERROR\nft: %d\nrl: %d\n\n", ret1, ret2) : 0; printf("\n\n");

ret1 = ft_printf("%x\n", 200);
ret2 = printf("%x\n", 200);
ret1 != ret2 ? printf("\n\n\n\nERROR\nft: %d\nrl: %d\n\n", ret1, ret2) : 0; printf("\n\n");

ret1 = ft_printf("ptr: %p\n", a);
ret2 = printf("ptr: %p\n", a);
ret1 != ret2 ? printf("\n\n\n\nERROR\nft: %d\nrl: %d\n\n", ret1, ret2) : 0; printf("\n\n");

ret1 = ft_printf("nullptr: %p\n", NULL);
ret2 = printf("nullptr: %p\n", NULL);
ret1 != ret2 ? printf("\n\n\n\nERROR\nft: %d\nrl: %d\n\n", ret1, ret2) : 0; printf("\n\n");

ret1 = ft_printf("real\nft\n");
ret2 = printf("real\nft\n");
ret1 != ret2 ? printf("\n\n\n\nERROR\nft: %d\nrl: %d\n\n", ret1, ret2) : 0; printf("\n\n");

ret1 = ft_printf("%05d\n", 123);
ret2 = printf("%05d\n", 123);
ret1 != ret2 ? printf("\n\n\n\nERROR\nft: %d\nrl: %d\n\n", ret1, ret2) : 0; printf("\n\n");

ret1 = ft_printf("%05d\n", 123);
ret2 = printf("%05d\n", 123);
ret1 != ret2 ? printf("\n\n\n\nERROR\nft: %d\nrl: %d\n\n", ret1, ret2) : 0; printf("\n\n");

ret1 = ft_printf("%5%\n");
ret2 = printf("%5%\n");
ret1 != ret2 ? printf("\n\n\n\nERROR\nft: %d\nrl: %d\n\n", ret1, ret2) : 0; printf("\n\n");

ret1 = ft_printf("%08x\n", 42);
ret2 = printf("%08x\n", 42);
ret1 != ret2 ? printf("\n\n\n\nERROR\nft: %d\nrl: %d\n\n", ret1, ret2) : 0; printf("\n\n");

ret1 = ft_printf("%05.3d\n", -42);
ret2 = printf("%05.3d\n", -42);
ret1 != ret2 ? printf("\n\n\n\nERROR\nft: %d\nrl: %d\n\n", ret1, ret2) : 0; printf("\n\n");

ret1 = ft_printf("%p\n%7pa\n", NULL, NULL);
ret2 = printf("%p\n%7pa\n", NULL, NULL);
ret1 != ret2 ? printf("\n\n\n\nERROR\nft: %d\nrl: %d\n\n", ret1, ret2) : 0; printf("\n\n");

ret1 = ft_printf("% h\n");
ret2 = printf("% h\n");
ret1 != ret2 ? printf("\n\n\n\nERROR\nft: %d\nrl: %d\n\n", ret1, ret2) : 0; printf("\n\n");

ret1 = ft_printf("%.3s\n", NULL);
ret2 = printf("%.3s\n", NULL);
ret1 != ret2 ? printf("\n\n\n\nERROR\nft: %d\nrl: %d\n\n", ret1, ret2) : 0; printf("\n\n");

ret1 = ft_printf("#%08.5x#\n", 0);
ret2 = printf("#%08.5x#\n", 0);
ret1 != ret2 ? printf("\n\n\n\nERROR\nft: %d\nrl: %d\n\n", ret1, ret2) : 0; printf("\n\n");

ret1 = ft_printf("#%#-3x#\n", 0);
ret2 = printf("#%#-3x#\n", 0);
ret1 != ret2 ? printf("\n\n\n\nERROR\nft: %d\nrl: %d\n\n", ret1, ret2) : 0; printf("\n\n");

ret1 = ft_printf("\n###\n%.10f\n", d);
ret2 = printf("\n###\n%.10f\n", d);
ret1 != ret2 ? printf("\n\n\n\nERROR\nft: %d\nrl: %d\n\n", ret1, ret2) : 0; printf("\n\n");

ret1 = ft_printf("%.10f\n###\n", d);
ret2 = printf("%.10f\n###\n", d);
ret1 != ret2 ? printf("\n\n\n\nERROR\nft: %d\nrl: %d\n\n", ret1, ret2) : 0; printf("\n\n");

ret1 = ft_printf("&ft_printf: %p\n", &ft_printf);
ret2 = printf("&ft_printf: %p\n", &ft_printf);
ret1 != ret2 ? printf("\n\n\n\nERROR\nft: %d\nrl: %d\n\n", ret1, ret2) : 0; printf("\n\n");

ret1 = printf("&printf   : %p\n", &printf);
ret2 = printf("&printf   : %p\n", &printf);
ret1 != ret2 ? printf("\n\n\n\nERROR\nft: %d\nrl: %d\n\n", ret1, ret2) : 0; printf("\n\n");

ret1 = printf("&var      : %p\n", &d);
ret2 = printf("&var      : %p\n", &d);
ret1 != ret2 ? printf("\n\n\n\nERROR\nft: %d\nrl: %d\n\n", ret1, ret2) : 0; printf("\n\n");

ret1 = ft_printf("&ft_printf: %p\n", &printf);
ret2 = printf("&ft_printf: %p\n", &printf);
ret1 != ret2 ? printf("\n\n\n\nERROR\nft: %d\nrl: %d\n\n", ret1, ret2) : 0; printf("\n\n");

d = 0.999999;
ret1 = ft_printf("ft:%f\n", d);
ret2 = printf("ft:%f\n", d);
ret1 != ret2 ? printf("\n\n\n\nERROR\nft: %d\nrl: %d\n\n", ret1, ret2) : 0; printf("\n\n");

d = 0.9999999;
ret1 = ft_printf("ft:%f\n", d);
ret2 = printf("ft:%f\n", d);
ret1 != ret2 ? printf("\n\n\n\nERROR\nft: %d\nrl: %d\n\n", ret1, ret2) : 0; printf("\n\n");

d = -0.000001;
ret1 = ft_printf("ft:%f#\n", d);
ret2 = printf("ft:%f#\n", d);
ret1 != ret2 ? printf("\n\n\n\nERROR\nft: %d\nrl: %d\n\n", ret1, ret2) : 0; printf("\n\n");

d = -3.99;
ret1 = ft_printf("ft:%.1f#\n", d);
ret2 = printf("ft:%.1f#\n", d);
ret1 != ret2 ? printf("\n\n\n\nERROR\nft: %d\nrl: %d\n\n", ret1, ret2) : 0; printf("\n\n");

ret1 = ft_printf("%.3s\n", "hello");
ret2 = printf("%.3s\n", "hello");
ret1 != ret2 ? printf("\n\n\n\nERROR\nft: %d\nrl: %d\n\n", ret1, ret2) : 0; printf("\n\n");

ret1 = ft_printf("%p\n", &d);
ret2 = printf("%p\n", &d);
ret1 != ret2 ? printf("\n\n\n\nERROR\nft: %d\nrl: %d\n\n", ret1, ret2) : 0; printf("\n\n");

ret1 = ft_printf("#%20p#\n", &d);
ret2 = printf("#%20p#\n", &d);
ret1 != ret2 ? printf("\n\n\n\nERROR\nft: %d\nrl: %d\n\n", ret1, ret2) : 0; printf("\n\n");

ret1 = ft_printf("#%15p#\n", &d);
ret2 = printf("#%15p#\n", &d);
ret1 != ret2 ? printf("\n\n\n\nERROR\nft: %d\nrl: %d\n\n", ret1, ret2) : 0; printf("\n\n");

ret1 = ft_printf("#%-20p#\n", &d);
ret2 = printf("#%-20p#\n", &d);
ret1 != ret2 ? printf("\n\n\n\nERROR\nft: %d\nrl: %d\n\n", ret1, ret2) : 0; printf("\n\n");

ret1 = ft_printf("#%-15p#\n", &d);
ret2 = printf("#%-15p#\n", &d);
ret1 != ret2 ? printf("\n\n\n\nERROR\nft: %d\nrl: %d\n\n", ret1, ret2) : 0; printf("\n\n");

d = -2147483648.99999999999999;
ret1 = ft_printf("#%f#\n", d);
ret2 = printf("#%f#\n", d);

/*
printf("\n\n\n\n#############\nBONUSES\n#############\n\n\n");
ft_printf("Binary:\n");
int j;
for (unsigned int i = 0; i < 17; ++i) {
	ft_printf("%d: #", i);
	j = ft_printf("%b", i);
	ft_printf("# (return value between #s = %d)\n", j);
}
ft_printf("%d: %b\n", 255, 255);
ft_printf("%d: %b\n", 256, 256);
ft_printf("%d: %b\n", 257, 257);
int x = 9;
ft_printf("%d 0-padded to width 8: #", x);
int y = ft_printf("%08b", x);
ft_printf("# (return value between #s = %d)\n", y);

ft_printf("\n\n####\nTESTING COLORS\n#####\n\n");
ret1 = ft_printf("%{blue}blue%{}normal\n");
ret2 = printf("\e[44mblue\e[0mnormal\n");
ret1 != ret2 ? printf("\n\n\n\nERROR\nft: %d\nrl: %d\n\n", ret1, ret2) : 0; printf("\n\n");

ret1 = ft_printf("%{blue}bl%[bred]ue%{}normal\n");
ret2 = printf("\e[44mbl\e[1;91mue\e[0mnormal\n");
ret1 != ret2 ? printf("\n\n\n\nERROR\nft: %d\nrl: %d\n\n", ret1, ret2) : 0; printf("\n\n");

ret1 = ft_printf("%{yellow}bl%[red]ue%[]normal\n");
ret2 = printf("\e[43mbl\e[0;91mue\e[0mnormal\n");
ret1 != ret2 ? printf("\n\n\n\nERROR\nft: %d\nrl: %d\n\n", ret1, ret2) : 0; printf("\n\n");

ret1 = ft_printf("redbg%[bblue]%{bred}blue%{}normal\n");
ret2 = printf("redbg\e[1;94m\e[41mblue\e[0mnormal\n");
ret1 != ret2 ? printf("\n\n\n\nERROR\nft: %d\nrl: %d\n\n", ret1, ret2) : 0; printf("\n\n");

ret1 = ft_printf("%{yellowbl%[red]ue%[]normal\n");
ft_printf("As this extends standard printf functionality, there is no equivalent test for this. This is here to demonstrate that it won't crash.\n\n");


ft_printf("\n\n####\nTESTING MEMORY PRINTING\n#####\n\n");
int l[] = {3, 255, 256, 257};
ret1 = ft_printf("%16.16m\n", &l);
ret2 = printf("03 00 00 00 ff 00 00 00 00 01 00 00 01 01 00 00\n");
ret1 != ret2 ? printf("\n\n\n\nERROR\nft: %d\nrl: %d\n\n", ret1, ret2) : 0; printf("\n\n");

ret1 = ft_printf("%16.8m\n", &l);
ret2 = printf("003 000 000 000 377 000 000 000 000 001 000 000 001 001 000 000\n");
ret1 != ret2 ? printf("\n\n\n\nERROR\nft: %d\nrl: %d\n\n", ret1, ret2) : 0; printf("\n\n");

ret1 = ft_printf("%8.2m\n", &l);
ret2 = printf("00000011 00000000 00000000 00000000 11111111 00000000 00000000 00000000\n");
ret1 != ret2 ? printf("\n\n\n\nERROR\nft: %d\nrl: %d\n\n", ret1, ret2) : 0; printf("\n\n");


ret1 = ft_printf("%.2m\n", &l);
ret1 = ft_printf("%8m\n", &l);
ret1 = ft_printf("%8.3m\n", &l);
ret1 = ft_printf("#%3.8m#\n", &l);
ret1 = ft_printf("#%8.16M#\n", &l);

int file = open("test", O_WRONLY);
ft_printf_fd(file, "Testing ft_printf_fd...\n%f\n%d\n#%-5x#", 123.456, 123456, 253);
close(file);

ret1 = ft_printf("%.0p, %.p\n", 0, 0);
ret2 = printf("%.0p, %.p\n", 0, 0);
ret1 != ret2 ? printf("\n\n\n\nERROR\nft: %d\nrl: %d\n\n", ret1, ret2) : 0; printf("\n\n");

ret1 = ft_printf("#%.0p#, #%.p#\n", 0, 0);
ret2 = printf("#%.0p#, #%.p#\n", 0, 0);
ret1 != ret2 ? printf("\n\n\n\nERROR\nft: %d\nrl: %d\n\n", ret1, ret2) : 0; printf("\n\n");

*/

return 0;
}
