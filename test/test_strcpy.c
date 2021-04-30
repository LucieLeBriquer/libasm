#include "tester.h"

void	test_strcpy(void)
{
	char dest[20];
	char dest2[20];
	char *src;

	printt("STRCPY");
	src = "Hello world!";
	errno = 0;
	printf("orig : src[%s], dest[%s]", src, strcpy(dest, src));
	printf("\terrno = %d\n", errno);
	errno = 0;
	printf("mine : src[%s], dest[%s]", src, ft_strcpy(dest2, src));
	printf("\terrno = %d\n", errno);

	src = "";
	errno = 0;
	printf("orig : src[%s], dest[%s]", src, strcpy(dest, src));
	printf("\t\t\t\terrno = %d\n", errno);
	errno = 0;
	printf("mine : src[%s], dest[%s]", src, ft_strcpy(dest2, src));
	printf("\t\t\t\terrno = %d\n", errno);
	printf("\n");
}
