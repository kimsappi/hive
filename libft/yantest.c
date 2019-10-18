/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 11:22:24 by yyan              #+#    #+#             */
/*   Updated: 2019/10/18 17:35:46 by yyan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
​
#include "libft.h"
#include <stdio.h>
​
void	printarray(int *ar, int n)
{
	int i;
​
	i = 0;
	while (i < n)
	{
		printf("%d\n", ar[i]);
		i++;
	}
}
​
void	give_value(char *s, char *s2, int *ar, int *ar2)
{
	bzero(s, 50);
	bzero(s2, 50);
	strcpy(s, "This is string.h library function");
	strcpy(s2, "This is string.h library function");
​
	bzero(ar, 12);
	bzero(ar2, 12);
	ar[0] = 1;
	ar[1] = 3;
	ar[2] = 6;
	
	ar2[0] = 1;
	ar2[1] = 3;
	ar2[2] = 6;
}
​
int main(void)
{
	char str[50];
	char str2[50];
	char *src;
	int ar[4];
	int ar2[3];
​
	src = "hello";
​
	//for testing ft_memset
	printf("\t----TESTING FT_MEMSET----\n\n");
	give_value(str, str2, ar, ar2);
	memset(str, '$', 10);
	printf("\tString after memset()\n%s\n\n", str);
	ft_memset(str2, '$', 10);
	printf("\tString after ft_memset()\n%s\n\n", str2);
	
	memset(ar,8, 8);
	printf("\tArray after memset()\n");
	printarray(ar, 3);
	ft_memset(ar2, 8, 8);
	printf("\tArray after ft_memset()\n");
	printarray(ar2, 3);
	printf("\n");
​
	// for testing bzero
	printf("\t----TESTING BZERO----\n\n");
	give_value(str, str2, ar, ar2);
	bzero(str, 10);
	printf("\tstring after bzero()\n%s\n\n", str);
	ft_bzero(str2, 10);
	printf("\tstring after ft_bzero()\n%s\n\n", str2);
	
	bzero(ar,2);
	printf("\tArray after bzero()\n");
	printarray(ar, 3);
	ft_bzero(ar2, 2);
	printf("\tArray after ft_bzero()\n");
	printarray(ar2, 3);
	printf("\n");
​
	//for testing memcpy
	printf("\t----TESTING MEMCPY----\n\n");
	give_value(str, str2, ar, ar2);
	memcpy(str, src, 4);
	printf("\tstring after ft_memcpy()\n%s\n\n", str);
	ft_memcpy(str2, src, 4);
	printf("\tstring after memcpy()\n%s\n\n", str2);
	
	memcpy(str, ar, 4);
	printf("\tArray after memcpy()\n");
	printarray(ar, 3);
	ft_memcpy(str, ar, 4);
	printf("\tArray after ft_memcpy()\n"); 
	printarray(ar, 3);
	printf("\n");
​
	//for testing memccpy
	printf("\t----TESTING MEMCCPY----\n\n");
	char msg[100] = "This is the string: not copied";
	char buffer[80];
​
	memset( buffer, '\0', 80);
	memccpy(buffer, msg, ':', 80);
	printf("\tstring after memccpy()\n%s\n\n", buffer);
	bzero(buffer, 80);
	ft_memccpy(buffer,msg, ':', 80);
	printf("\tstring after ft_memccpy()\n%s\n\n", buffer);
​
	// for testing memmove
	printf("\t----TESTING MEMMOVE()----\n\n");
	memmove( msg + 5, msg, strlen(msg) + 1);
	printf("\tString after memmove()\n%s\n", msg);
	strcpy(msg, "This is the string: not copied");
	ft_memmove(msg+5, msg, strlen(msg) + 1);
	printf("\tString after ft_memmove()\n%s\n", msg);
	
	printf("\tArray before memmove\n");
	printarray(ar, 4);
	memmove(&ar[1], ar, 12);
	printf("\tArray after memmove()\n");
	printarray(ar, 4);
	printf("\tArray after ft_memmove()\n");
	printarray(ar, 4);
	printf("\n");
​
	// for testing memchr
	printf("\t----TESTING MEMCHR----\n\n");
	char string[100] = "Learn C from trytoprogram.com";
	char ch = 't';
	printf("str = %s\n\n", string);
	printf("\tMEMCHR--Remaining string after '%c' : %s\n", ch, (char *) memchr(string, ch, strlen(string)));
	printf("\tFT_MEMCHR--Remaining string after '%c' : %s\n", ch, (char *) ft_memchr(string, ch, strlen(string)));
	
	printf("\tMEMCHR--Remaining array after '%d' : %d\n", 3, (int *) memchr( ar, 3, sizeof(ar)));
	printf("\tFT_MEMCHR--Remaining array after '%d' : %d\n\n", 3, (int *) ft_memchr( ar, 3, sizeof(ar)));
​
	// for testing memcmp
	printf("\t----TESTING MEMCMP----\n\n");
	char *strx = "Learn C";
	printf("\tMEMCMP--Comparing two strings: %d\n", memcmp( strx,string,  9));
	printf("\tFT_MEMCMP-Comparing two strings: %d\n", ft_memcmp( strx,string,  9));
	
	printf("\tMEMCMP--Comparing two arrays: %d\n", memcmp(ar, ar2, 16));
	printf("\tFT_MEMCMP--Comparing two arrays: %d\n\n", ft_memcmp(ar, ar2, 16));
​
	// for testing strlen:
	printf("\t----TESTING STRLEN----\n\n");
	printf("\tSTRLEN--length of the string is :%d\n", strlen(string));
	printf("\tFT_STRLEN--length of the string is :%d\n\n", ft_strlen(string));
	
	// for testing strdup:
	printf("\t----TESTING STRDUP----\n\n");
	char *string2 = strdup(string);
	char *string3 = ft_strdup(string);
	printf("\tSTRdup--the duplicated string is :%s\n", string2);
	printf("\tFT_STRdup--the duplicated string is :%s\n\n",string3);
​
	// for testing strcpy:
	printf("\t----TESTING STRCPY----\n\n");
	strcpy(str, "Hive helsinki, good morning good afternoon");
	printf("\tSTRCPY--the copied string is: %s\n", strcpy(string, str));
	printf("\tFT_STRCPY--the copied string is: %s\n\n", ft_strcpy(string, str));
​
	// for testing strncpy:
	printf("\t----TESTING STRNCPY----\n\n");
	strcpy(string, "Learn C from trytoprogram.com");
	printf("String is: %s\n",  string);
	printf("The original str is : %s\n", str);
	printf("\tSTRNCPY--the copied string is: %s\n", strncpy(string, str, 10));
	printf("\tFT_STRNCPY--the copied string is: %s\n\n", ft_strncpy(string, str, 10));
​
	// for testing strcmp:
	printf("\t----TESTING STRCMP----\n\n");
	printf("\tstrcmp--Comparing two strings: %d\n", strcmp(string, str));
	printf("\tFT_strcmp--Comparing two strings: %d\n\n", ft_strcmp(string, str));
​
	// for testing strcat:
	printf("\t----TESTING STRCAT----\n\n");
	strcpy(string, "Learn C from trytoprogram.com");
	strcpy(string, "Learn C from trytoprogram.com");
	printf("\tSTRCAT--Cated string is: %s\n", strcat(string, str));
	strcpy(string, "Learn C from trytoprogram.com");
	strcpy(string, "Learn C from trytoprogram.com");
	printf("\tFT_STRCAT--Cated string is: %s\n\n", ft_strcat(string, str));
​
	// for testing strncat:
	printf("TESTING STRNCAT\n");
	strcpy(string, "Learn C from trytoprogram.com");
	printf("\tSTRNCAT--Cated string is: %s\n", strncat(string, str, 8));
	strcpy(string, "Learn C from trytoprogram.com");
	printf("\tFT_STRNCAT--Cated string is: %s\n\n", ft_strncat(string, str, 8));
​
	// for testing strlcat:
	printf("\t----TESTING STRLCAT----\n\n");
	char ch1[100] ="Hello Helsinki";
	char *ch2 = "123456788978788";
	size_t a = strlcat(ch1, ch2, 25);
	printf("STRLCAT--The result is:\n %s\n the value returned is : %d\n", ch1, a);
	strcpy(ch1, "Hello Helsinki");
	size_t b = ft_strlcat(ch1, ch2, 25);
	printf("FT_STRLCAT--The result is:\n %s\n the value returned is : %d\n\n", ch1, b);
​
	// for testing strchr:
	printf("\t----TESTING STRCHR----\n\n");
	printf("STRCHR--The result is: \n %s\n", (char*)strchr(ch1, 'i'));
	printf("FT_STRCHR--The result is: \n %s\n\n", (char*)ft_strchr(ch1, 'i'));
​
	// for testing strrchr:
	printf("\t----TESTING STRRCHR----\n\n");
	printf("STRRHR--The result is: \n %s\n", (char*)strrchr(ch1, 'l'));
	printf("FT_STRRHR--The result is: \n %s\n\n", (char*)ft_strrchr(ch1, 'l'));
​
	// for testing strstr;
	printf("\t----TESTING STRSTR----\n\n");
	printf("STRSTR--The result is: \n %s\n", (char*)strstr(ch1, "elsi"));
	printf("FT_STRSTR--The result is: \n %s\n\n", (char*)ft_strstr(ch1, "elsi"));
​
	// for testing strnstr:
	printf("\t----TESTING STRNSTR----\n\n");
	printf("STRNSTR--The result is: \n %s\n", (char*)strnstr(ch1, "1234567889",30 ));
	printf("FT_STRNSTR--The result is: \n %s\n\n", (char*)ft_strnstr(ch1, "1234567889", 30));
​
	// for testing isalpha:
	printf("\t----TESTING isalpha----\n\n");
	printf("isalpha--The result is: \n %d\n", isalpha(101));
	printf("ft_isalpha--The result is: \n %d\n\n", ft_isalpha(101));
	
	// for testing isdigit:
	printf("\t----TESTING isdigit----\n\n");
	printf("isdigit--The result is: \n %d\n", isdigit('8'));
	printf("ft_isdigit--The result is: \n %d\n\n", ft_isdigit('8'));
​
	// for testing isalnum:
	printf("\t----TESTING isalnum----\n\n");
	printf("isalnum--The result is: \n %d\n", isalnum('a'));
	printf("ft_isalnum--The result is: \n %d\n\n", ft_isalnum('a'));
​
	// for testing isascii:
	printf("\t----TESTING isascii----\n\n");
	printf("isascii--The result is: \n %d\n", isalnum(178));
	printf("ft_isascii--The result is: \n %d\n\n", ft_isalnum(178));
​
	// for testing isprint:
	printf("\t----TESTING isprint----\n\n");
	printf("isprint--The result is: \n %d\n", isprint(126));
	printf("ft_isprint--The result is: \n %d\n\n", ft_isprint(126));
​
	// for testing toupper:
	printf("\t----TESTING toupper----\n\n");
	printf("toupper--The result is: \n %c\n", toupper('a'));
	printf("ft_toupper--The result is: \n %c\n\n", ft_toupper('a'));
​
	// for testing tolower:
	printf("\t----TESTING tolower----\n\n");
	printf("tolower--The result is: \n %c\n", tolower('L'));
	printf("ft_tolower--The result is: \n %c\n\n", ft_tolower('L'));
​
	// for testing atoi:
	printf("\t----TESTING atoi----\n\n");
	printf("atoi--The result is: \n %d\n", atoi(" \t\v\r -892hig90e"));
	printf("ft_atoi--The result is: \n %d\n\n", ft_atoi(" \t\v\r -892hig90e"));
	return(0);
}