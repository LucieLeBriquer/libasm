#include "tester.h"

void	test_strcmp(void)
{
	char *s;
	char *s2;

	printt("STRCMP");
	s = "Hello world !";
	s2 = "Hell!";
	errno = 0;
	printf("mine : s1[%s], s2[%s]\tret = %d", s, s2, ft_strcmp(s, s2));
	printf("\terrno = %d\n", errno);
	errno = 0;
	printf("orig : s1[%s], s2[%s]\tret = %d", s, s2, strcmp(s, s2));
	printf("\terrno = %d\n", errno);

	s = "H";
	s2 = "Hello";
	errno = 0;
	printf("mine : s1[%s], s2[%s]\t\t\tret = %d", s, s2, ft_strcmp(s, s2));
	printf("\terrno = %d\n", errno);
	errno = 0;
	printf("orig : s1[%s], s2[%s]\t\t\tret = %d", s, s2, strcmp(s, s2));
	printf("\terrno = %d\n", errno);

	s = "Hello";
	s2 = "Hello";
	errno = 0;
	printf("mine : s1[%s], s2[%s]\t\tret = %d", s, s2, ft_strcmp(s, s2));
	printf("\t\terrno = %d\n", errno);
	errno = 0;
	printf("orig : s1[%s], s2[%s]\t\tret = %d", s, s2, strcmp(s, s2));
	printf("\t\terrno = %d\n", errno);
	
	printf("\n");
}
