/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksappi <ksappi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 12:38:34 by ksappi            #+#    #+#             */
/*   Updated: 2019/10/18 16:58:05 by ksappi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include "strnstr.c"
#include "strlcat.c"

void	ft_putcharptr(char *c)
{
	if (c)
		printf("%c", *c);
}

void ft_putcharptri(unsigned int i, char *c) {if (c) printf("%c", *c + i);}

char ft_smap(char c) { return c + 1; }

char ft_smapi(unsigned int i, char c) {return c + i;}

int	main(void)
{
	int *test = malloc(4);
	int *real = malloc(4);
	char *x;
	char *tests = malloc(4);
	char *reals = malloc(4);
	char *tests2 = malloc(4);
	char *reals2 = malloc(4);
	size_t ret;
	size_t ret2;


	ft_putendl("TESTS BEGIN HERE\nThere shouldn't be any errors or warnings above this(?).");

	*test = 999999999;
	ft_memset(test, 150, 4);
	*real = 999999999;
	memset(real, 150, 4);
	if (memcmp(real, test, 4))
		printf("memset fail\n");

	ft_bzero(test, 4);
	bzero(real, 4);
	if (memcmp(real, test, 4))
		printf("bzero fail\n");

	*real = 999999999;
	ft_memcpy(test, real, 4);
	if (memcmp(real, test, 4))
		printf("memcpy fail\n");

	ft_putendl("all g up to memcpy?");

// TODO HUGE ERROR WITH MEMCCPY DOESNT WORK WITHOUT X WORKAROUND

	strcpy(tests, "123");
	strcpy(reals, "abc");
	x = ft_memccpy(tests, reals, 'x', 4);
	if (x)
		printf("memccpy1 fail\n");
	if (memcmp(tests, reals, 4))
		printf("memccpy2 fail\n");
	x = (char *)ft_memccpy(tests, reals, 'b', 4);
	if (memcmp(reals, tests, 4))
		printf("memccpy3 fail\n");
	if (*x != 'c')
		printf("memccpy4 fail\n");

	if (ft_memchr(tests, 'x', 4))
		printf("memchr1 fail\n");
	if (ft_memchr(tests, 'b', 4) != memchr(tests, 'b', 4))
		printf("memchr2 fail\n");

	strcpy(tests, "12c");
	strcpy(reals, "abc");
	tests = ft_memmove(tests, reals, 1);
	if (!memcmp(reals, tests, 4))
		printf("memmove fail\n");
	x = ft_memmove(tests, reals, 2);
	if (memcmp(reals, tests, 4))
		printf("memmove2 fail\n");
	if (x != tests)
		ft_putendl("memmove3 fail");
	char	srcm[] = "lorem ipsum dolor sit amet";
	char	*testm;
	testm = srcm + 1;
	write(1, testm, 22);
	printf("\n");
	testm = ft_memmove(testm, "consectetur", 5);
	write(1, testm, 22);
	printf("\n");
	testm = ft_memmove(testm, "con\0sec\0\0te\0tur", 10);
	write(1, testm, 22);
	printf("\n");
	testm = ft_memmove(testm, srcm, 8);
	write(1, testm, 22);
	printf("\n");
	ft_memmove(srcm, testm, 8);
	write(1, testm, 22);
	printf("\n");	

	if (ft_memcmp(reals, tests, 4))
		ft_putendl("memcmp fail");
	strcpy(reals, "123");
	strcpy(tests, "223");
	if (ft_memcmp(reals, tests, 4) >= 0)
		ft_putendl("memcmp2 fail");
	if (ft_memcmp(tests, reals, 4) <= 0)
		ft_putendl("memcmp3 fail");

	if (ft_strlen(reals) != 3)
		ft_putendl("strlen fail");
	
	ft_putendl("all g up to strdup?");

	x = ft_strdup(reals);
	if (memcmp(x, reals, 4))
		printf("strdup fail\n");
	free(x);
	x = ft_strdup("");
	if (!x)
		ft_putendl("strdup2 fail");
	if (*x)
		ft_putendl("strdup3 fail");

	strcpy(reals, "12");
	strcpy(tests, "223");
	tests = ft_strcpy(tests, reals);
	if (memcmp(tests, reals, 3))
		ft_putendl("strcpy1 fail");
	ft_strcpy(tests, "");
	if (memcmp(tests, &reals[2], 1))
		ft_putendl("strcpy2 fail");

	strcpy(reals, "abc");
	strcpy(tests, "123");
	ft_strncpy(tests, "abc", 1);
	if (strcmp("a23", tests))
		printf("strncpy1 fail\n");
	ft_strncpy(tests, "abcdefg", 3);
	if (strcmp("abc", tests))
		printf("strncpy2 fail\n");
	char *testnc = calloc(50, 1);
	memset(testnc, 's', 13);
	strncpy(testnc, "", 3);
	printf("%d %d %d %d %d\n", testnc[0], testnc[1], testnc[2], testnc[3], testnc[4]);
	
	strcpy(tests, "");
	ft_strcat(tests, "1");
	if (strcmp(tests, "1"))
		ft_putendl("strcat1");
	ft_strcat(tests, "23");
	if (strcmp(tests, "123"))
		ft_putendl("strcat2");

	strcpy(tests, "");
	ft_strncat(tests, "12345", 3);
	if (strcmp(tests, "123"))
		ft_putendl("strcat2");

	ft_putendl("all g up to strncat?");

	strcpy(reals, "abc");
	strcpy(tests, "");
	strcpy(reals2, "abc");
	strcpy(tests2, "");
	ret = ft_strlcat(tests, reals, 4);
	ret2 = strlcat(tests2, reals2, 4);
	if (ret != ret2)
		ft_putendl("strlcat1");
	if (memcmp(tests, tests2, 4))
		ft_putendl("strlcat2");
	strcpy(tests, "");
	strcpy(tests2, "");
	ret = ft_strlcat(tests, reals, 3);
	ret2 = strlcat(tests2, reals2, 3);
	if (ret != ret2)
		ft_putendl("strlcat3");
	if (memcmp(tests, tests2, 3))
		ft_putendl("strlcat4");
	strcpy(tests, "asd");
	strcpy(tests2, "asd");
	ret = ft_strlcat(tests, reals, 1);
	ret2 = strlcat(tests2, reals2, 1);
	if (ret != ret2)
		ft_putendl("strlcat5");
	if (memcmp(tests, tests2, 3))
		ft_putendl("strlcat6");
	strcpy(tests, "asd");
	strcpy(tests2, "asd");
	ret = ft_strlcat(tests, reals, 0);
	ret2 = strlcat(tests2, reals2, 0);
	if (ret != ret2)
		ft_putendl("strlcat7");
	if (memcmp(tests, tests2, 3))
		ft_putendl("strlcat8");
	free(reals2);
	free(tests2);

	reals = strchr("abcabbcbabc", 'c');
	tests = ft_strchr("abcabbcbabc", 'c');
	if (strcmp(reals, tests))
		ft_putendl("strchr1 fail");
	reals = strchr("abcabbcbabc", 'x');
	tests = ft_strchr("abcabbcbabc", 'x');
	if (tests)
		ft_putendl("strchr2 fail");

	reals = strrchr("abcabbcbabc", 'c');
	tests = ft_strrchr("abcabbcbabc", 'c');
	if (strcmp(reals, tests))
		ft_putendl("strrchr1 fail");
	reals = strrchr("abcabbcbabc", 'x');
	tests = ft_strrchr("abcabbcbabc", 'x');
	if (tests)
		ft_putendl("strrchr2 fail");

	ft_putendl("all g up to strrchr?");

	reals = strstr("abababcabababc", "ababc");
	tests = ft_strstr("abababcabababc", "ababc");
	if (strcmp(reals, tests))
		ft_putendl("strstr1 fail");
	reals = strstr("ababababababc", "ababc");
	tests = ft_strstr("ababababababc", "ababc");
	if (strcmp(reals, tests))
		ft_putendl("strstr2 fail");
	reals = strstr("ababababababc", "");
	tests = ft_strstr("ababababababc", "");
	if (strcmp(reals, tests))
		ft_putendl("strstr3 fail");
	if (ft_strstr("abc", "x"))
		ft_putendl("strstr4 fail");
	if (ft_strstr("", "x"))
		ft_putendl("strstr5 fail");
	if (!ft_strstr("", ""))
		ft_putendl("strstr6 fail");


	reals = strnstr("abababcabababc", "ababc", 20);
	tests = ft_strnstr("abababcabababc", "ababc", 20);
	if (strcmp(reals, tests))
		ft_putendl("strnstr1 fail");
	reals = strnstr("ababababababc", "ababc", 20);
	tests = ft_strnstr("ababababababc", "ababc", 20);
	if (strcmp(reals, tests))
		ft_putendl("strnstr2 fail");
	reals = strnstr("ababababababc", "", 20);
	tests = strnstr("ababababababc", "", 20);
	if (strcmp(reals, tests))
		ft_putendl("strnstr3 fail");
	if (ft_strnstr("abc", "x", 20))
		ft_putendl("strnstr4 fail");
	reals = strnstr("ababababababc", "", 10);
	tests = strnstr("ababababababc", "", 10);
	if (strcmp(reals, tests))
		ft_putendl("strnstr5 fail");
	reals = strnstr("ababababababc", "", 11);
	tests = strnstr("ababababababc", "", 11);
	if (strcmp(reals, tests))
		ft_putendl("strnstr6 fail");
	reals = strnstr("ababababababc", "", 12);
	tests = strnstr("ababababababc", "", 12);
	if (strcmp(reals, tests))
		ft_putendl("strnstr7 fail");
	reals = strnstr("ababababababc", "", 13);
	tests = strnstr("ababababababc", "", 13);
	if (strcmp(reals, tests))
		ft_putendl("strnstr8 fail");
	if (ft_strnstr("", "x", 1))
		ft_putendl("strnstr9 fail");
	if (!ft_strnstr("", "", 1))
		ft_putendl("strnstr10 fail");

	ft_putendl("THESE ERRORS BETWEEN #### AREN'T REAl ERRORS UNLESS THE SIGNS ARE DIFFERENT\n##############################################");
	if (strcmp("abc", "abc") != ft_strcmp("abc", "abc"))
		ft_putendl("strcmp1");
	printf("strcmp: %d ft_: %d\n", strcmp("abc", "abx"), ft_strcmp("abc", "abx"));
	if (strcmp("abc", "abx") != ft_strcmp("abc", "abx"))
		ft_putendl("huom strcmp2");
	printf("strcmp: %d ft_: %d\n", strcmp("abc", "aba"), ft_strcmp("abc", "aba"));
	if (strcmp("abc", "aba") != ft_strcmp("abc", "aba"))
		ft_putendl("huom strcmp3");
	char a[4] = { 1,2,3,0 };
	char b[4] = { 1,2,-3,0 };
	printf("strcmp: %d ft_: %d\n", strcmp(a, b), ft_strcmp(a, b));
	char c[4] = { 1,2,3,0 };
	char d[4] = { 1,2,10,0 };
	printf("strcmp: %d ft_: %d\n", strcmp(c, d), ft_strcmp(c, d));
	char e[4] = { 1,2,'a',0 };
	char f[4] = { 1,2,'x',0 };
	printf("strcmp: %d ft_: %d\n", strcmp(e, f), ft_strcmp(e, f));
	char s1[4] = "abc";
	char s2[4] = "aba";
	printf("strcmp: %d ft_: %d\n", strcmp(s1, s2), ft_strcmp(s1, s2));
	// Oh well they here now so why baleet

	printf("strncmp: %d ft_: %d\n", strncmp("abc", "abc", 5), ft_strncmp("abc", "abc", 5));
	if (strncmp("abc", "abc", 5) != ft_strncmp("abc", "abc", 5))
		ft_putendl("strncmp1");
	printf("strncmp: %d ft_: %d\n", strncmp("abc", "abc", 2), ft_strncmp("abc", "abc", 2));
	if (strncmp("abc", "abc", 2) != ft_strncmp("abc", "abc", 2))
		ft_putendl("strncmp2");
	printf("strncmp: %d ft_: %d\n", strncmp("abc", "aba", 5), ft_strncmp("abc", "aba", 5));
	if (strncmp("abc", "aba", 5) != ft_strncmp("abc", "aba", 5))
		ft_putendl("strncmp3");
	printf("strncmp: %d ft_: %d\n", strncmp("abc", "abx", 5), ft_strncmp("abc", "abx", 5));
	if (strncmp("abc", "abx", 5) != ft_strncmp("abc", "abx", 5))
		ft_putendl("strncmp4");
	printf("strncmp: %d ft_: %d\n", strncmp(a, b, 4), ft_strncmp(a, b, 4));
	ft_putendl("##############################################");

	char *atoi1 = "";
	char *atoi2 = "5";
	char *atoi3 = "-5";
	char *atoi4 = "- 5";
	char *atoi5 = "+5";
	char *atoi6 = "\t\n  \n 5";
	char *atoi7 = "a5";
	char *atoi8 = "5a";
	char *atoi9 = "\t\n  \n 5 \t";
	char *atoi10 = "5-";
	char *atoi11 = "0";
	char *atoi12 = "2147483647";
	char *atoi13 = "-2147483648";
	char *atoi14 = "2147483648";
	char *atoi15 = "99999999999999";
	char *atoi16 = "\e10";
	if (atoi(atoi1) != ft_atoi(atoi1))
		ft_putendl("atoi1");
	if (atoi(atoi2) != ft_atoi(atoi2))
		ft_putendl("atoi1a");
	if (atoi(atoi3) != ft_atoi(atoi3))
		ft_putendl("atoi1b");
	if (atoi(atoi4) != ft_atoi(atoi4))
		ft_putendl("atoi1d");
	if (atoi(atoi5) != ft_atoi(atoi5))
		ft_putendl("atoi1f");
	if (atoi(atoi6) != ft_atoi(atoi6))
		ft_putendl("atoi1g");
	if (atoi(atoi7) != ft_atoi(atoi7))
		ft_putendl("atoi1h");
	if (atoi(atoi8) != ft_atoi(atoi8))
		ft_putendl("atoi1u");
	if (atoi(atoi9) != ft_atoi(atoi9))
		ft_putendl("atoi1q");
	if (atoi(atoi10) != ft_atoi(atoi10))
		ft_putendl("atoi1ukj");
	if (atoi(atoi11) != ft_atoi(atoi11))
		ft_putendl("atoi1hdg");
	if (atoi(atoi12) != ft_atoi(atoi12))
		ft_putendl("atoi1fsdg");
	if (atoi(atoi13) != ft_atoi(atoi13))
		ft_putendl("atoi1fds");
	if (atoi(atoi14) != ft_atoi(atoi14))
		ft_putendl("atoi1fd");
	if (atoi(atoi15) != ft_atoi(atoi15))
		ft_putendl("atoi15");
	if (atoi(atoi16) != ft_atoi(atoi16))
		ft_putendl("atoi16");

	if (ft_isalpha('a' - 1) || ft_isalpha('z' + 1))
		ft_putendl("isalpha1");
	if (!ft_isalpha('a') || !ft_isalpha('z') || !ft_isalpha('k'))
		ft_putendl("isalpha2");

	if (ft_isdigit(5) || ft_isdigit(47))
		ft_putendl("idigit1");
	if (!ft_isdigit('0') || !ft_isdigit('5') || !ft_isdigit('9'))
		ft_putendl("isdigit2");

	if (ft_isalnum('a' - 1) || ft_isalnum('z' + 1))
		ft_putendl("isalnum1");
	if (!ft_isalnum('a') || !ft_isalnum('z') || !ft_isalnum('0'))
		ft_putendl("isalnum2");

	if (ft_isascii(-1) || ft_isascii(128))
		ft_putendl("isascii1");
	if (!ft_isascii(0) || !ft_isascii(5) || !ft_isascii(127))
		ft_putendl("isascii2");

	if (ft_isprint(' ' - 1) || ft_isprint('~' + 1))
		ft_putendl("isprint1");
	if (!ft_isprint(' ') || !ft_isprint('~') || !ft_isprint(42))
		ft_putendl("isprint2");

	if (ft_toupper('a') != 'A')
		ft_putendl("toupper1");
	if (ft_toupper('z') != 'Z')
		ft_putendl("toupper2");
	if (ft_toupper('A') != 'A')
		ft_putendl("toupper3");
	if (ft_toupper('a' - 1) != 'a' - 1)
		ft_putendl("toupper4");

	if (ft_tolower('a') != 'a')
		ft_putendl("ft_tolower1");
	if (ft_tolower('Z') != 'z')
		ft_putendl("ft_tolower1");
	if (ft_tolower('A') != 'a')
		ft_putendl("ft_tolower1");
	if (ft_tolower('A' - 1) != 'A' - 1)
		ft_putendl("ft_tolower1");

	ft_putendl("---------------------");
	ft_putendl("Standard library functions end here");
	ft_putendl("---------------------");

		// Here goes additional functions
	int zeroint = 0;
	tests = ft_memalloc(4);
	if (memcmp(&zeroint, tests, 4))
		printf("memalloc\n");

	ft_memdel((void **)(&tests));
	if (tests)
		printf("memdel\n");
	tests = NULL;
	void **ntest = NULL;
	ft_memdel((void **)(&tests));
	ft_memdel(ntest);

	ft_putendl("passes memdel without segfault");

	tests = ft_strnew(4);
	if (memcmp(&zeroint, tests, 4))
		printf("strnew\n");

	ft_strdel(&tests);
	if (tests)
		printf("strdel\n");
	tests = NULL;
	ft_memdel((void **)(&tests));
	ft_memdel(ntest);

	tests = ft_strnew(4);
	strcpy(tests, "asd");
	ft_strclr(tests);
	if (memcmp(tests, &zeroint, 4))
		printf("strclr\n");
	char *ntest2 = NULL;
	ft_strclr(ntest2);

	ft_putendl("passes strclr without segfault");

	strcpy(tests, "asd");
	ft_putendl("The next 2 lines should match (ft_striter):\nasd");
	ft_striter(tests, &ft_putcharptr);
	printf("\n\n");
	ft_striter(ntest2, &ft_putcharptr);
	ft_striter(ntest2, NULL);
	ft_striter(tests, NULL);

	ft_putendl("The next 2 lines should match(ft_striteri):\natf");
	ft_striteri(tests, &ft_putcharptri);
	printf("\n\n");
	ft_striteri(NULL, &ft_putcharptri);
	ft_striter(NULL, NULL);
	ft_striter(tests, NULL);

	int p = 999999999;
	memcpy(tests, &p, 4);
	tests = ft_strmap("asd", &ft_smap);
	if (strcmp(tests, "bte"))
		ft_putendl("strmap");
	ft_strmap(NULL, &ft_smap);
	ft_strmap(NULL, NULL);
	ft_strmap(tests, NULL);
		
	memcpy(tests, &p, 4);
	strcpy(tests, "asd");
	tests = ft_strmapi("asd", &ft_smapi);
	if (strcmp(tests, "atf"))
		ft_putendl("strmapi");
	ft_strmapi(NULL, &ft_smapi);
	ft_strmapi(NULL, NULL);
	ft_strmapi(tests, NULL);

	if (ft_strequ("asdfdsg", "asdfgsh"))
		printf("strequ\n");
	if (ft_strequ("abcde", "abcde") != 1)
		ft_putendl("strequ2");
	ft_strequ(NULL, NULL);
	ft_strequ("abc", NULL);
	ft_strequ(NULL, "abc");

	if (ft_strnequ("asdfgh", "asdfgg", 5) != 1)
		printf("strnequ\n");
	if (ft_strnequ("abc", "abd", 2) != 1)
		ft_putendl("strnequ2");
	if (ft_strnequ("abc", "abc", 5) != 1)
		printf("strnequ3\n");
	if (ft_strnequ("abcd", "abce", 4))
		ft_putendl("strnequ4");
	if (ft_strnequ(NULL, NULL, 10))
		ft_putendl("strnequnull");
	ft_strnequ(NULL, "asd", 5);
	ft_strnequ("asd", NULL, 5);

	ft_putendl("strnequ passed without segfault");

	if (strcmp(ft_strsub("12345", 2, 2), "34"))
		ft_putendl("strsub1");
	if (strcmp(ft_strsub("12345", 0, 1), "1"))
		ft_putendl("strsub2");
	if (strcmp(ft_strsub("12345", 0, 0), ""))
		ft_putendl("strsub3");
	ft_strsub(NULL, 5, 5);

	if (strcmp(ft_strjoin("abc", "12345"), "abc12345"))
		ft_putendl("join1");
	if (strcmp(ft_strjoin("", "1"), "1"))
		ft_putendl("join2");
	if (strcmp(ft_strjoin("1", ""), "1"))
		ft_putendl("join3");
	ft_strjoin(NULL, "1");
	ft_strjoin(NULL, NULL);
	ft_strjoin("1", NULL);


	return 0;
}
