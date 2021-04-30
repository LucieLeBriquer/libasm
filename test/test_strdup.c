#include "tester.h"

void	test_strdup(void)
{
	char	*str1;
	char	*str2;

	printt("STRDUP");
	str1 = strdup("Hello");
	printf("orig : %s\n", str1);
	str2 = ft_strdup("Hello");
	printf("mine : %s\n", str2);
	free(str1);
	free(str2);
	printf("\n");
}
