#include "tester.h"

void	test_strlen(void)
{
	char *s;

	printt("STRLEN");
	s = "Lucie";
	errno = 0;
	printf("mine : [%s]\tret = %ld", s, ft_strlen(s));
	printf("\terrno = %d\n", errno);
	errno = 0;
	printf("orig : [%s]\tret = %ld", s, strlen(s));
	printf("\terrno = %d\n", errno);

	s = "";
	errno = 0;
	printf("mine : [%s]\t\tret = %ld", s, ft_strlen(s));
	printf(" \terrno = %d\n", errno);
	errno = 0;
	printf("orig : [%s]\t\tret = %ld", s, strlen(s));
	printf(" \terrno = %d\n", errno);
	printf("\n");
}
